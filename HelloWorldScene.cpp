
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// On "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    //1. Obtener propiedades de la pantalla
    auto tamVisible = Director::getInstance()->getVisibleSize();
    Vec2 origen = Director::getInstance()->getVisibleOrigin();

    //2. Colocando la imagen de fondo
    auto spriteFondo = Sprite::create("Images/earth.png");
    spriteFondo->setPosition(Vec2(origen.x + tamVisible.width / 2, origen.y + tamVisible.height/2));
    this->addChild(spriteFondo, 0); //Añadir la imagen a la pantalla



    //3. Ícono de cerrar para salir de la pantalla. Se crea como un menu item.
    auto closeItem = MenuItemImage::create("Images/CloseNormal.png", "Images/CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem != nullptr)
    {   //Establecer la posición del ícono de cerrar
        float x = origen.x + tamVisible.width - closeItem->getContentSize().width/2;
        float y = origen.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // Crear el menú que contiene el ícono de cerrar
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1); //Añadir el menú a la pantalla


    //4. Crear el label de "Hola mundo"
    auto label = Label::createWithTTF("Hola Mundo", "fonts/Marker Felt.ttf", 48);
    if (label != nullptr)
    {
        //Posicionar el label en el centro de la pantalla
        label->setPosition(Vec2(origen.x + tamVisible.width/2,
                                origen.y + tamVisible.height - label->getContentSize().height));

        // Añadir el label a la pantalla
        this->addChild(label, 1);
    }

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Cierra la escena del juego y sale de la aplicación
    Director::getInstance()->end();
}
