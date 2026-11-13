# best luck

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