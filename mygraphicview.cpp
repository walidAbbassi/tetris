
#include "mygraphicview.h"
#include "objects/horse.h";
void MyGraphicView::setDefaultSettings()
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
}

void MyGraphicView::setSceneAndGroups()
{
    scene = new QGraphicsScene();   // Инициализируем сцену для отрисовки
    this->setScene(scene);          // Устанавливаем сцену в виджет

    group_1 = new QGraphicsItemGroup(); // Инициализируем первую группу элементов
    group_2 = new QGraphicsItemGroup(); // Инициализируем вторую группу элементов

    scene->addItem(group_1);            // Добавляем первую группу в сцену
    scene->addItem(group_2);
}

void MyGraphicView::initTimer()
{
    timer = new QTimer();               // Инициализируем Таймер
    // Подключаем СЛОТ для отрисовки к таймеру
    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
}

MyGraphicView::MyGraphicView(QWidget *parent)
    : QGraphicsView(parent)
{
    setDefaultSettings();
    setSceneAndGroups();
    initTimer();
}

MyGraphicView::~MyGraphicView()
{

}

void MyGraphicView::slotAlarmTimer()
{
    /* Удаляем все элементы со сцены,
     * если они есть перед новой отрисовкой
     * */
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);

    int width = this->width();      // определяем ширину нашего виджета
    int height = this->height();    // определяем высоту нашего виджета


    scene->setSceneRect(0,0,width,height);
    Horse *horse = new Horse(10,10);
    horse->drawUnits(scene);

    group_1->addToGroup(horse);

}

/* Этим методом перехватываем событие изменения размера виджет
 * */
void MyGraphicView::resizeEvent(QResizeEvent *event)
{
    timer->start(50);   // Как только событие произошло стартуем таймер для отрисовки
    QGraphicsView::resizeEvent(event);  // Запускаем событие родителького класса
}


/* Метод для удаления всех элементов из группы
 * */
void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
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
