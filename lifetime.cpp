/**
 *  人生就像一段程序，沿着主线稳定推进，
 *  直到那次不愿 rollback 的 exception，
 *  惟愿选择 keep，往后余生再无 break。
 *
 *  —— 这一版，是真的能编译、能跑、能 return 0 的。
 *     编译： g++ -std=c++20 -O2 lifetime.cpp -o lifetime
 **/
#include <algorithm>
#include <iostream>
#include <limits>
#include <optional>   // 可选（你曾不是必然，如今是全部）
#include <string>

using Luck = long long;

struct You {
    std::string name;
};

// 在遇见你之前，"最好" 还没有定义。
struct Best {
    std::string who = "undefined";
    int worth = 0;

    static Best undefined() { return Best{}; }
    Best() = default;
    Best(const You& you) : who(you.name), worth(100) {}  // 你一出现，就有了定义

    friend bool operator<(const Best& a, const Best& b) { return a.worth < b.worth; }
    friend std::ostream& operator<<(std::ostream& os, const Best& b) { return os << b.who; }
};

struct Life {
    Best best = Best::undefined();
    Luck luck = 0;
    bool heartbeat = true;
    int years = 0;

    bool alive() const { return heartbeat; }

    void runAsPlanned() {
        std::cout << "[main] 按部就班，风平浪静。\n";
        throw You{"你"};   // 直到那次 exception —— 不愿 rollback
    }

    void keep(const You& you) {
        std::cout << "[keep you] 决定留下 " << you.name << "，不回到从前。\n";
    }

    void cherish(const You& you) {
        ++years;
        // 珍惜不是 break，是把日子一天天过完
        if (years % 25 == 0)
            std::cout << "  [cherish] 第 " << years << " 年：仍在珍惜 " << you.name << "。\n";
        if (years >= 100) heartbeat = false;   // 不是 break，是一生走完了
    }
};

static bool meet(const You&) {
    return true;   // 概率极低，但它就是发生了
}

int main() {
    Life me;
    You you{"你"};

    try {
        me.runAsPlanned();
    } catch (const You& caught) {        
        std::cout << "[exception] 一次最美好的意外。\n";
        you = caught;
        // 显式指定 <Best>：你本不是同一类型，是我愿意为你做的那次隐式转换。
        me.best = std::max<Best>(me.best, you);
        std::cout << "[best max]  从此最好的，是 " << me.best << "。\n";
        me.keep(you);
    }

    std::optional<You> maybe = std::nullopt;  // 你曾不是必然
    maybe = you;                              // 如今是全部

    if (meet(you)) [[unlikely]] {
        me.luck = std::numeric_limits<Luck>::max();
        std::cout << "[luck max] 运气值已拉满：" << me.luck << "。\n";
    }

    while (me.alive()) {
        me.cherish(you);
    }

    std::cout << "\n一生圆满，无遗憾。\n";
    return 0;
}