


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
        desc: "王家卫八年磨一剑，囊括第33届香港电影金像奖揽12项大奖！",
        star: 0, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic7.iqiyipic.com/image/20210621/55/94/v_160260694_m_601_480_270.jpg", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "西瓜视频", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 863439283923, // 播放数
        likeNums: 38293,    // 点赞数
        collectNums: 23,    // 收藏数
        forwardNums: 23,    // 转发数
        tag: "vlog", // 标签，可能为空
        comment: "美丽绿色武功山之行,一生值得一去的地方"
    },
    {
        id: "2",
        title: "玉龙雪山",
        desc: "边城梅花庵遭人埋伏意外身亡，成为武林一段扑朔迷离的公案……",
        star: 3, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic9.iqiyipic.com/image/20210622/e6/a4/v_112846088_m_601_m3_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "抖音", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 323, // 播放数
        likeNums: 293,    // 点赞数
        collectNums: 23323,    // 收藏数
        forwardNums: 33323,    // 转发数
        tag: "景点", // 标签，可能为空
        comment: "丽江玉龙雪山"
    },
    {
        id: "3",
        title: "速度与激情",
        desc: "该剧讲述了贺顿（杨紫 饰）通过心理咨询，解析多位来访者心理问题的成因，在相应的心理治疗中，帮助他们走出过往的心理阴霾，重新拥抱生活的动人故事。这一路上，贺顿和电台主播钱开逸（井柏然 饰）、意外结识的好友叶家辉（王嘉 饰）以及闺蜜汤莉莉（菅纫姿 饰）一起，在一系列笑与泪交织的经历中疗愈他人也收获了自愈。",
        star: 2, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic4.iqiyipic.com/image/20210604/81/a4/v_159888228_m_601_320_180.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "西瓜视频", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 233333355323, // 播放数
        likeNums: 2333844493,    // 点赞数
        collectNums: 2323,    // 收藏数
        forwardNums: 323,    // 转发数
        tag: "动作", // 标签，可能为空
        comment: "经典美国动作大片" // 备注
    },
    {
        id: "4",
        title: "007",
        desc: "一起和王自健、蛋蛋、王建国聊一聊那些腻的事情！",
        star: 5, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic5.iqiyipic.com/image/20210615/8e/a4/v_160107478_m_601_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "腾讯视频", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 23323, // 播放数
        likeNums: 2393,    // 点赞数
        collectNums: 3323,    // 收藏数
        forwardNums: 323,    // 转发数
        tag: "经典系列", // 标签，可能为空
        comment: ""
    },
    {
        id: "5",
        title: "玉龙雪山",
        desc: "唐代奇侠组团破迷案",
        star: 4, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic9.iqiyipic.com/image/20210622/e6/a4/v_112846088_m_601_m3_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "爱奇艺", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 4300, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 90323, // 播放数
        likeNums: 23293,    // 点赞数
        collectNums: 13323,    // 收藏数
        forwardNums: 923,    // 转发数
        tag: "景点", // 标签，可能为空
        comment: ""
    },
    {
        id: "6",
        title: "鸿蒙相较于安卓系统有哪些优点？为什么大多数人常用微信支付，而不是支付宝支付？原因找到了",
        desc: "鸿蒙相较于安卓系统有哪些优点？为什么大多数人常用微信支付，而不是支付宝支付？原因找到了",
        star: 4, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic4.iqiyipic.com/image/20210604/81/a4/v_159888228_m_601_320_180.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "腾讯视频", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 0, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 33623, // 播放数
        likeNums: 2953,    // 点赞数
        collectNums: 2323,    // 收藏数
        forwardNums: 33323,    // 转发数
        tag: "", // 标签，可能为空
        comment: ""
    },
    {
        id: "7",
        title: "五大爆款SUV齐换代：宝马X1取消\“鸡腿挡把\”，CR-V\“大变样\”！",
        desc: "1941年。进步青年、英租界警务处探长冯九思亲眼目睹了他的入党介绍人的牺牲。日军大本营派遣阴险的小仓直人来到天津，为占领英法租界做准备。小仓严密布局，利用残忍的秋本，对天津抗日组织开始了一系列的破坏。冯九思满怀加入中共党组织的热情，在短时间内，既要查清小仓直人的阴谋，也要向中共党组织证明自己的清白。中共上级领导指派杨炳新与办案经验丰富的冯九思合作。冯九思与杨炳新最初的合作并不顺利，然而，保卫国家，追求伟大理想的信念让他们一步一步相互了解，在与日军战斗的过程中相互信任，在生死关头的多次考验让他们肝胆相照。",
        star: 3, // 星级
        mediaType: 0, // 媒体类型，0为视频，1为音频
        coverUrl: "https://pic9.iqiyipic.com/image/20210622/e6/a4/v_112846088_m_601_m3_260_360.jpg?caplist=jpg,webp,avif", // 封面图片
        localFileName: "", // 本地文件名称
        urlFileName: "", // 网络文件名称
        sourceType: 0, // 来源类型,0为本地,1为网络
        sourceName: "抖音", // 来源名称,本地则为空,比如西瓜视频等
        createTime: "", // 创建时间,即第一次添加时间
        modifyTime: "", // 最后一次观看时间
        totalTimes: 4800, //总时间长度,单位:秒
        lastTimes: 0, // 上次观看历史位置
        playNums: 3323, // 播放数
        likeNums: 293,    // 点赞数
        collectNums: 23323,    // 收藏数
        forwardNums: 33323,    // 转发数
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
