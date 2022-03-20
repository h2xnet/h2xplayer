#include "app.h"

#include "h2xbase/file/file_util.h"
#include "h2xbase/log/log.h"
#include "src/cache/database_cache.h"

#include <QQmlEngine>

namespace  {

//
// AppSingleProvider : 应用单例
//
static QObject* AppSingleProvider(QQmlEngine *engine, QJSEngine *scriptEngine) {
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    App* inst = App::getInstance();
    return inst;
}

}

App* App::inst_ = nullptr;

App* App::getInstance() {
    if (!App::inst_) {
        App::inst_ = new App();
    }
    return App::inst_;
}

App::App(QObject* parent) : QObject(parent) {

}

App::~App() {

}

bool App::initApp(int argc, char* argv[]) {
    int status = -1;

    // 初始化日志
    status = h2xbase::Log::open(QString("h2xplayer.log"), QtMsgType::QtDebugMsg);
    qDebug("App::initApp log open status: %d\n", status);

    // 初始化缓存
    QString strCachePath = h2xbase::FileUtil::GetAppDataPath() + "/cache/";
    if (h2xbase::FileUtil::PathIsExist(strCachePath, true)) {
        QString strCacheFile = strCachePath + "databaseCache.sqlite";

        status = db_cache_.open(strCacheFile, 0);
        qDebug("App::initApp open cache status: %d\n", status);
    }

    return true;
}

void App::uninitApp() {
    // 关闭缓存
    db_cache_.close();

    // 关闭日志
    h2xbase::Log::close();
}

//
// registMetaType : 注册类型
//
void App::registMetaType() {

    // 注册应用类
    qmlRegisterSingletonType<App>("h2xplayer.net.pc", 1, 0, "AppId", AppSingleProvider);  //
}
