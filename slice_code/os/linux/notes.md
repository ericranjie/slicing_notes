commit c0ecd6388360d930440cc5554026818895199923 (HEAD -> master, origin/master, origin/HEAD)
Merge: 183d46ff422e 5560a612c20d
Author: Linus Torvalds <torvalds@linux-foundation.org>
Date:   Thu Aug 1 11:30:15 2024 -0700

We use comment tag to mark code block, in order to decrease next time's reading burden.

// Algo: 算法&数据结构

// Out: 直接goto出局（Linux特有风格）
// Err: 直接错误出局

// Guard:
// Loop:
// Branch:
// Ignore:
// Appendix: 附录（模块）
// Trace: 跟踪点 插桩点
// Module: 模块

// Lock:
// Unlock:
// Trylock:
// Sync:
// Sched: 调度点
// Init: 变量初始化

// Getter:
// Setter:

// Debug:

// Atomic:
// Trans: 结构体转换

// Main:(High-Complexity) 主要工作例程
// (Entrance) 主入口


// Drill: 内部主下钻例程
// Aux: 辅助例程
// Export: 外部例程
// Worker: 普通工作例程
// Wrap: 上层包装例程
// Arbitor: 仲裁历程
// Integrate: 上位统合例程

// (High-Complexity)