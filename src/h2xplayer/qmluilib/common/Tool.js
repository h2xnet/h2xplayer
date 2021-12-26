
/*
 * Function: printMsg
 * Desc: 打印消息日志
 * Author: zfs
 * Date: 2021-12-26 10:28
 * @msg: 打印的消息内容
 * @containsDateTime: 为true代表消息已经包含日期时间，为false代表不包含日志时间
 * @logType: 日志类型，小于0不打印，0为调试（Debug），1为消息(Info)，2为警告(Warning)，3为错误(Error)，4为严重错误(Fatal)，默认是1
 */
function printMsg(msg, containsDateTime = false, logType=1) {
    switch(logType) {
    case 0:
        console.log("Debug: " + msg);
        break;
    case 1:
        console.log("Info: " + msg);
        break;
    case 2:
        console.log("Warning: " + msg);
        break;
    case 3:
        console.log("Error: " + msg);
        break;
    case 4:
        console.log("Fatal: " + msg);
        break;
    default:
        console.log("Exit: " + msg);
        break;
    }
}
