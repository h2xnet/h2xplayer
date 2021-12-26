


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
        id:"",
        name: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "" // 标签，可能为空
    },
    {
        id:"",
        name: "",
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        tag: "" // 标签，可能为空
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
