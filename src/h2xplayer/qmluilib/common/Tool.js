
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

/*
 * Function: getTimeStr
 * Desc: 获取时间字符串（把时间长度转换成字符串时间长度）
 * Author: zfs
 * Date: 2022-01-01 22:52
 * @times: 被转换的时间长度，单位：秒
 * 返回值: 时：分：秒 格式字符串
 */
function getTimeStr(times) {
    if (times < 0 ) {
        return '';
    }

    let hours = Math.floor(times / 3600);
    let minue = Math.floor((times - hours * 3600) / 60);
    let sec = Math.floor(times - hours * 3600 - minue * 60);

    let str = '';
    if (hours < 10) {
        str = '0';
    }
    str = str + hours.toString() + ':';

    if (minue < 10) {
        str = str + '0';
    }
    str = str + minue.toString() + ':';

    if (sec < 10) {
        str = str + '0';
    }
    str = str + sec.toString();

    return str;
}

/*
 * Funcion: getTwoDecimal
 * Desc: 保留两位小数值，不进行四舍五入
 * Author: zfs
 * Date: 2022-01-03 15:29
 */
function getTwoDecimal(num) {
    return Math.floor(num * 100) / 100
}

/*
 * Funcion: getNumberStr
 * Desc: 获取数量字符串（把数字转换成字符串形式）
 * Author: zfs
 * Date: 2022-01-03 15:19
 */
function getNumberStr(num) {
    if (num <= 0) {
        return 0;
    }
    else if (num < 10000) {
        // 小于1万则不变
        return num;
    }
    else if (num < 100000000) {
        // 万为单位
        return getTwoDecimal(num / 10000) + '万';
    }
    else if (num < 1000000000000) {
        // 亿为单位
        return getTwoDecimal(num / 100000000) + '亿'
    }
    else {
        return getTwoDecimal(num / 1000000000000) + '万亿'
    }
}
