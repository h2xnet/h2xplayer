#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include "h2xbase/h2xbase_export.h"

#include <QString>

namespace h2xbase {

/*
 * ClassName: FileUtil
 * Desc: 文件联合处理类
 * Author: zfs
 * Date: 2022-03-19 16:58
 */
class H2XBASE_API FileUtil
{
public:
    FileUtil() = delete ;
    ~FileUtil() = delete ;

    /*
     * Function: GetAppPath
     * Desc: 获取应用路径
     * Author: zfs
     * Date: 2022-03-19 17:49
     */
    static QString GetAppPath();

    /*
     * Function: GetAppDataPath
     * Desc: 获取应用缓存路径
     * Author: zfs
     * Date: 2022-03-19 17:25
     */
    static QString GetAppDataPath();

    /*
     * Function: PathIsExist
     * Desc: 判断路径是否存在
     * Author: zfs
     * Date: 2022-03-19 17:53
     * @path: 被判断的路径
     * @create: 如果不存在，是否创建标志
     */
    static bool PathIsExist(QString path, bool create = true);

    /*
     * Function: ReadFileAll
     * Desc: 读取文件内容
     * Author: zfs
     * Date: 2022-03-26 10:31
     * @fileName: 文件名称
     * 返回值：返回读取到的内容
     */
    static QString ReadFileAll(const QString& fileName);

    /*
     * Function: WriteFile
     * Desc: 写文件内容，每次都会新建
     * Author: zfs
     * Date: 2022-03-26 10:32
     * @fileName: 文件名称
     * @data: 写入的数据
     * 返回值：成功返回0,否则返回错误代码
     */
    static int WriteFile(const QString& fileName, const QString& data);

};

} // end namespace h2xbase

#endif // FILE_UTIL_H
