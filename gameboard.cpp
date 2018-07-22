
#include "gameboard.h"
#include "objects/horse.h";
#include <QString>
#include "ui_tetris.h"
void Gameboard::setDefaultSettings()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
}

void Gameboard::setSceneAndGroups()
{
    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
    group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов

    scene->addItem(group_1);            // Добавляем первую группу в сцену
    scene->addItem(group_2);
}

void Gameboard::initTimer()
{
    timer = new QTimer();               // Инициализируем Таймер
    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
}

Gameboard::Gameboard(Ui::Tetris *ui, QWidget *parent)
    : QGraphicsView(parent)
{
    this->ui = ui;

    setDefaultSettings();
    setSceneAndGroups();

    Horse *horse = new Horse(10,10);
    current = horse;
    scene->addItem(current);

    initTimer();
}

Gameboard::~Gameboard()
{

}

void Gameboard::slotAlarmTimer()
{
    /* Удаляем все элементы со сцены,
     * если они есть перед новой отрисовкой
     * */
    this->deleteItemsFromGroup(current);
    this->deleteItemsFromGroup(group_2);
    current->deleteHorseDraws();

    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета


    scene->setSceneRect(0,0,width,height);

    repaintCount++;
    ui->statusBar->showMessage(QString::number(repaintCount));

    ui->lable_score->setText(current->getCoords());
    current->drawUnits(scene);
}

/* Этим методом перехватываем событие изменения размера виджет
 * */
void Gameboard::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}


/* Метод для удаления всех элементов из группы
 * */
void Gameboard::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    /* Перебираем все элементы сцены, и если они принадлежат группе,
     * переданной в метод, то удаляем их
     * */
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
       if(item->group() == group ) {
          delete item;
       }
    }
}
