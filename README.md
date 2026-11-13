# best luck

example：[https://www.sharky.xin/]

```cpp
/**
  人生就像一段程序，沿着主线稳定推进，
  直到那次不愿 rollback 的 exception，
  唯愿选择 keep，往后余生再无 break。
**/
#include <lifetime>
#include <limits>
#include <optional>

struct Life {
    Best best = Best::undefined(); 
    Luck luck = 0;
    bool heartbeat = true;
    bool alive() const { return heartbeat; }
};

int main() {
    Life me;

    try {
        me.runAsPlanned();
    }
    catch (const You& you) {
        me.best = std::max(me.best, you);
        me.keep(you);
    }

    if (meet(you)) [[unlikely]] {
        me.luck = std::numeric_limits<Luck>::max();
    }

    while (me.alive()) {
        me.cherish(you);
    }
    return 0;
}
```

## 一句话概括
> 你是我今生最美好的意外，遇见你是我一生中最幸运的事，往后余生，心跳不息、珍惜不止、永不分离。

## 逐段解读

| 代码 | 字面含义 | 背后的情话 |
|---|---|---|
| `best_luck.cpp` | 源文件名 | "最好的运气"——遇见你就是我最大的幸运 |
| 不愿 `rollback` 的 `exception` | 异常不回滚 | 你是个美丽的意外，我不后悔、不想退回从前 |
| 再无 `break` | 不中断循环 | 不离不弃 |
| `#include <lifetime>` `<limits>` `<optional>` | 引入头文件 | 一生、极限、可选——你曾不是必然，如今是全部 |
| `Best best = Best::undefined()` | "最好"未定义 | 在遇见你之前，我不知道什么是最好的 |
| `Luck luck = 0` / `heartbeat = true` | 初始化 | 运气为零，但心还活着 |
| `me.runAsPlanned()` | 按计划执行 | 原本平淡、按部就班的生活 |
| `catch (const You& you)` | 捕获异常 | 你的出现打乱了一切；`const` 引用＝独一无二、不可改变的你 |
| `std::max(me.best, you)` | 取最大值 | 你胜过我以往所有的"最好" |
| `me.keep(you)` | 自定义方法 | 把你留下 |
| `if (meet(you)) [[unlikely]]` | C++20 概率属性 | 标记"遇见你"是极低概率事件＝难得的缘分 |
| `numeric_limits<Luck>::max()` | 类型最大值 | 遇见你，运气值直接拉满 |
| `while (me.alive()) me.cherish(you);` | 无限循环 | 有生之年，一直珍惜你（且没有 `break`） |
| `return 0` | 正常退出 | 一生圆满收尾，无异常、无遗憾 |
