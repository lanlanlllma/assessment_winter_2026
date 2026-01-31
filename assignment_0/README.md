# assignment0：基础 C++ 语法与应用题

目标：练习最基础的输入输出、分支循环、数组/字符串、简单 struct+容器。**本作业不提供参考实现**，你需要在 `src/` 下完成代码（空骨架已给）。
- 请勿修改其他目录下的任何文件，否则可能导致自动化测试失败。
- 前8道题目是基础题，后3道是工程拓展题（可选做，难度更大，更贴近真实工程）。
## 构建与运行
在仓库根目录：

```bash
cmake -S assignment_0 -B build/assignment_0 -DCMAKE_BUILD_TYPE=Release
cmake --build build/assignment_0 --config Release

# 运行（示例）
./build/assignment_0/a0_01_temperature

# 运行测试（默认不编译选做题 A0-09~11；默认不含参考实现）
ctest --test-dir build/assignment_0 -C Release --output-on-failure

# 编译选做题 A0-09~11（可选）
cmake -S assignment_0 -B build/assignment_0 -DCMAKE_BUILD_TYPE=Release -DA0_BUILD_OPTIONAL_09_11=ON
cmake --build build/assignment_0 --config Release

# CI（GitHub Actions）里也提供同等开关：手动运行工作流 `ci` 并设置输入 `a0_build_test=true`；如需编译选做题再设置 `a0_optional=true`

```

---

## 题目 A0-01：温度转换
**描述**：输入摄氏温度 C（double），输出华氏温度 F。

公式：`F = C * 9 / 5 + 32`

**输入**：一行，一个实数 C

**输出**：一行，一个实数 F，保留 2 位小数

**样例**：
- 输入：`0`
- 输出：`32.00`

---

## 题目 A0-02：闰年判断
**描述**：输入年份 y（int），判断是否闰年。

规则：能被 400 整除是闰年；或能被 4 整除但不能被 100 整除是闰年。

**输入**：一行，一个整数 y

**输出**：是闰年输出 `YES`，否则输出 `NO`

**样例**：
- 输入：`2000`
- 输出：`YES`

---

## 题目 A0-03：区间求和
**描述**：输入两个整数 l、r（保证 l<=r），输出 `[l, r]` 所有整数之和。

**输入**：一行，两个整数 l r

**输出**：一行，一个整数（注意可能很大，用 long long）

**样例**：
- 输入：`1 5`
- 输出：`15`

---

## 题目 A0-04：统计元音
**描述**：输入一行字符串（可能包含空格），统计其中元音字母数量（a/e/i/o/u，不区分大小写）。

**输入**：一行字符串

**输出**：一行，一个整数（元音数量）

**样例**：
- 输入：`Hello World`
- 输出：`3`

---

## 题目 A0-05：简单成绩统计（struct + vector）
**描述**：输入 n，然后输入 n 行：`name score`（name 无空格，score 为整数）。

你需要输出：
1) 最高分同学的名字与分数
2) 平均分（保留 2 位小数）

若出现并列最高分，输出**最先出现**的那位。

**输入**：
- 第一行：整数 n
- 接下来 n 行：字符串 name + 整数 score

**输出**：
- 第一行：`top=<name> <score>`
- 第二行：`avg=<avg>`

**样例**：
输入：
```
3
alice 80
bob 95
cindy 95
```
输出：
```
top=bob 95
avg=90.00
```

---

## 题目 A0-06：大整数加法（类 + 运算符重载）
**目标点**：类封装、字符串/向量、运算符重载、输出格式。

**描述**：实现一个 `BigInt` 类，支持非负十进制大整数（位数可达 10^5）。

需要支持：
- 构造：从 `std::string` / `const char*`
- `operator+`：大整数相加
- `operator<<`：输出十进制

主程序读取两行非负整数（可能很长），输出它们的和。

**输入**：两行字符串 `A`、`B`

**输出**：一行 `A+B`

**样例**：
输入：
```
999999999999999999
1
```
输出：
```
1000000000000000000
```

---

## 题目 A0-07：日志分析器（文件 IO + 字符串解析）
**目标点**：`std::ifstream`、逐行读取、解析、排序/统计。

**描述**：给定一个文件路径 `path`，文件每行格式：

```
<level> <ms>
```

其中 `level` 为 `INFO/WARN/ERROR` 之一，`ms` 为非负整数（耗时）。

你需要输出：
1) 三种 level 各自的条数
2) 平均耗时（所有行的 ms 平均值，保留 2 位小数）
3) 耗时最大的那一行（level 与 ms），若并列取最先出现

**输入**：一行：文件路径 path

**输出**：
```
INFO=<cnt>
WARN=<cnt>
ERROR=<cnt>
avg=<avg>
max=<level> <ms>
```

**样例**：
若文件内容为：
```
INFO 10
WARN 3
ERROR 100
INFO 7
```
输入：
```
log.txt
```
输出：
```
INFO=2
WARN=1
ERROR=1
avg=30.00
max=ERROR 100
```

---

## 题目 A0-08：RAII 文件句柄封装（RAII + 禁止拷贝 + 移动语义）
**目标点**：RAII、资源管理、Rule of 5、错误处理。

**描述**：实现一个 `FileHandle` 类来管理 `FILE*`（`<cstdio>`）。要求：
- 构造时打开文件（`fopen`），析构时自动 `fclose`
- **禁止拷贝**（拷贝构造/拷贝赋值 deleted）
- 支持**移动**（移动构造/移动赋值），移动后源对象置空
- 提供 `bool valid() const` 与 `FILE* get() const`

主程序：
- 读取 `input_path output_path`
- 用 `FileHandle` 打开输入输出
- 把输入文件所有内容原样拷贝到输出文件
- 成功输出 `OK`，失败输出 `FAIL`

**输入**：一行两个路径：`in out`

**输出**：`OK` 或 `FAIL`

---

# 工程拓展题（更贴近真实工程）

> 目标：在不引入第三方依赖的前提下，练习接口抽象、工厂/注册表、可扩展设计、配置/DSL 解析、健壮的错误处理。

## 题目 A0-09：插件式文本流水线（Registry + Factory + 多态）
**场景**：工程里经常会有“可配置的数据处理流水线”，通过配置选择处理步骤并串联执行。

你需要实现一个“文本变换流水线”，每个变换是一个插件（继承统一接口），由注册表按名字创建。

**输入**：
- 第 1 行：流水线描述 `pipeline`，格式为若干 step 用 `|` 连接：
  - `name` 或 `name:arg1:arg2...`
  - 示例：`trim|upper|replace:foo:bar`
- 第 2 行开始直到 EOF：若干行文本（允许空行、允许空格）

**输出**：对每一行输入文本，按流水线顺序执行变换后输出一行。

**要求**：
- 至少实现 3 个插件：
  1) `trim`：去掉首尾空白
  2) `upper`：转大写（仅处理 ASCII 字母即可）
  3) `replace:from:to`：将所有 `from` 子串替换为 `to`（允许 `to` 为空串）
- 若流水线描述非法/插件名未知/参数个数不对：输出 `FAIL` 并退出

**样例**：
输入：
```
trim|upper|replace:RM:ROBO
  rm 2026  
hello rm

```
输出：
```
ROBO 2026
HELLO ROBO

```

---

## 题目 A0-10：插件式告警规则引擎（可扩展规则）
**场景**：日志/遥测告警经常通过“规则配置”驱动；规则种类会不断增长，要求代码可扩展。

实现一个规则引擎：读取多条规则配置（每条规则是一个插件），然后逐行读取事件，统计每条规则命中次数，以及“至少命中一条规则”的事件数量。

**输入**：
- 第 1 行：整数 `m`（规则条数）
- 接下来 `m` 行：规则描述（每行一条）
  - `level>=INFO|WARN|ERROR`
  - `ms>number`
  - `msg_contains:substr`
- 后续直到 EOF：事件行，格式：
  - `<level> <ms> <message...>`（message 可能包含空格；整行除前两个字段外都属于 message）

**输出**：
- `rule1=<cnt>` ... `rulem=<cnt>`（按规则输入顺序）
- `total=<cnt>`（至少命中 1 条规则的事件行数量）

**要求**：
- 使用统一接口 `IRule::match(event)`，并用注册表按规则前缀创建对应规则对象
- 规则描述非法/未知规则类型：输出 `FAIL` 并退出

**样例**：
输入：
```
2
level>=WARN
ms>50
INFO 10 ok
WARN 60 motor overcurrent
ERROR 49 imu timeout
```
输出：
```
rule1=2
rule2=1
total=2
```

---

## 题目 A0-11：子命令分发器（Command 插件）
**场景**：工程里常见 `git` / `ros2` 这类“子命令”工具，新增功能通过新增 Command 类+注册即可接入。

实现一个子命令分发器：第一个 token 是子命令名，由注册表找到对应 Command 并执行。

**输入**：
- 第 1 个 token：`cmd`
- 剩余输入由不同 cmd 自行解析

需要至少实现 3 个子命令：
1) `head`：输入一个整数 `n`，然后读取剩余所有行，输出前 `n` 行
2) `grep`：输入一个字符串 `pattern`（不含空格），然后读取剩余所有行，输出包含 `pattern` 的行，格式：`<line_no>:<line>`（line_no 从 1 开始）
3) `wc`：读取剩余所有行，输出：
   - `lines=<L>`
   - `words=<W>`（用 `>>` 分词即可）
   - `chars=<C>`（含空格与换行；换行按输入行数计入 1 个字符）

**输出**：按对应子命令要求输出；未知子命令输出 `FAIL`。

**样例**：
输入：
```
grep rm
hello
rm2026
abc
```
输出：
```
2:rm2026
```
