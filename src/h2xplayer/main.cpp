#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>

#include "h2xplayer/app.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // 初始化应用
    bool bret = App::getInstance()->initApp(argc, argv);
    qDebug("main.cpp initApp status: %d\n", bret);

    // set icon
    app.setWindowIcon(QIcon("qrc:/imgs/logo_1.ico"));

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    int ret = app.exec();

    // 反初始化应用
    App::getInstance()->uninitApp();

    return ret;
}
