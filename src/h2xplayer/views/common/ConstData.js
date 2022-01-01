


var home_nav_datas_ = [
    {
        id: "playListId",
        name: "播放列表"
    },
    {
        id: "playHistoryId",
        name: "播放历史"
    },
    {
        id: "settingId",
        name: "设置"
    },
    {
        id: "aboutId",
        name: "关于"
    }
]

/*
 * Function: getHomeNavDatas
 * Desc: 获取首页导航栏数据
 * Author: zfs
 * Date: 2021-12-26 11:56
 */
function getHomeNavDatas() {
    return home_nav_datas_;
}

var play_list_test_datas_ = [
    {
        id: "1",
        title: "武功山之行,华为海思麒麟：2022年继续出发，向\“芯\”而行",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic7.iqiyipic.com/image/20210621/55/94/v_160260694_m_601_480_270.jpg", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "vlog", // 标签，可能为空
        comment: "美丽绿色武功山之行,一生值得一去的地方"
    },
    {
        id: "2",
        title: "玉龙雪山",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic9.iqiyipic.com/image/20210622/e6/a4/v_112846088_m_601_m3_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "景点", // 标签，可能为空
        comment: "丽江玉龙雪山"
    },
    {
        id: "3",
        title: "速度与激情",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic4.iqiyipic.com/image/20210604/81/a4/v_159888228_m_601_320_180.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "动作", // 标签，可能为空
        comment: "经典美国动作大片" // 备注
    },
    {
        id: "4",
        title: "007",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic5.iqiyipic.com/image/20210615/8e/a4/v_160107478_m_601_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "经典系列", // 标签，可能为空
        comment: ""
    },
    {
        id: "5",
        title: "玉龙雪山",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic9.iqiyipic.com/image/20210622/e6/a4/v_112846088_m_601_m3_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 4300, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "景点", // 标签，可能为空
        comment: ""
    },
    {
        id: "6",
        title: "鸿蒙相较于安卓系统有哪些优点？为什么大多数人常用微信支付，而不是支付宝支付？原因找到了",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic4.iqiyipic.com/image/20210604/81/a4/v_159888228_m_601_320_180.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "", // 标签，可能为空
        comment: ""
    },
    {
        id: "7",
        title: "五大爆款SUV齐换代：宝马X1取消\“鸡腿挡把\”，CR-V\“大变样\”！",
        desc: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic9.iqiyipic.com/image/20210622/e6/a4/v_112846088_m_601_m3_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 4800, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "", // 标签，可能为空
        comment: ""
    }
]
/*
 * Function: getPlayListTestDatas
 * Desc: 获取播放列表测试数据
 * Author: zfs
 * Date: 2021-12-26 16:26
 */
function getPlayListTestDatas() {
    return play_list_test_datas_;
}
