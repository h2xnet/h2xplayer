#ifndef APP_H
#define APP_H

#include "h2xcore/application.h"
#include "h2xplayer/src/cache/database_cache.h"
#include "h2xplayer/src/runmgr/application_run_manager.h"

#include <QObject>

/*
 * ClassName: App
 * Desc: 应用类，一个应用程序只能拥有一个应用类，主要完成一些全局功能
 * Author: zfs
 * Date: 2022-01-09 14:39
 */

class App : public QObject, public h2xcore::Application {
    Q_OBJECT;
public:
    static App* getInstance();

    virtual bool initApp(int argc, char* argv[]) override;

    virtual void uninitApp() override;

    void setRoot(QObject* root);
    QObject* getRoot() {    return root_;   }

    /*
     * Function: registMetaType
     * Desc: 注册元类型
     * Author: zfs
     * Date: 2022-03-20 12:29
     */
    void registMetaType();

    DatabaseCache& getDatabaseCache() {     return db_cache_;   }

protected:
    explicit App(QObject* parent = nullptr);
    ~App();

private:
    static App* inst_;

    // 根节点
    QObject* root_;

    // 数据库缓存
    DatabaseCache db_cache_;

    // 应用运行管理
    ApplicationRunManager app_run_mgr_;
};


#endif // APP_H
