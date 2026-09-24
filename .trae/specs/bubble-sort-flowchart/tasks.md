# 冒泡排序流程图 - 实施计划

## Task 1: 编写流程图绘制脚本
- **Status**: `completed`
- **Priority**: high
- **Depends On**: None
- **Description**:
  - 使用 Python + Pillow 编写 `draw_bubble_flowchart.py`，按设计好的坐标布局绘制标准流程图：
    - 圆角矩形：开始、结束；
    - 矩形：输入数组、i=0、j=0、交换、j=j+1、i=i+1；
    - 菱形：i<n-1、j<n-1-i、a[j]>a[j+1]；
    - 带箭头连线：顺序流向、是/否分支、内/外层循环回边；
    - 中文标注全部使用微软雅黑字体（`C:\Windows\Fonts\msyh.ttc`）；
    - 2 倍像素密度渲染，统一深蓝/浅蓝/橙色配色。
- **Acceptance Criteria Addressed**: AC-2, AC-3, AC-4
- **Test Requirements**:
  - `rule` TR-1.1: 脚本能无异常运行结束（退出码 0）
  - `rubric` TR-1.2: 布局规范性；scale 1-5；anchors 1/3/5 同 AC-4；threshold >= 4；evidence 为渲染图片目视
- **Notes**: R1 审查发现脚本从工作区丢失（Review R1 F-2），原完成证据失效，已重建。
- **Completion Evidence**:
  - TR-1.1: 2026-09-24 重跑 `python d:\vscode\c_practice\draw_bubble_flowchart.py`，输出"已保存: d:\vscode\c_practice\冒泡排序流程图.png 尺寸: (2000, 2080)"，退出码 0。
  - TR-1.2: 自评 5/5。脚本 [draw_bubble_flowchart.py](file:///d:/vscode/c_practice/draw_bubble_flowchart.py) 现经 Glob 确认真实存在；标准符号齐备；内/外层回边走左、右分离轨道；两处跨线用过桥弧，汇合点有实心圆点。

## Task 2: 生成并校验 PNG 产物
- **Status**: `completed`
- **Priority**: high
- **Depends On**: Task 1
- **Description**:
  - 运行脚本生成 `冒泡排序流程图.png`；
  - 用 Pillow 重新打开校验尺寸非零；
  - 人工目视核对全部节点文字、分支标签与循环回边，发现问题回到 Task 1 修正。
- **Acceptance Criteria Addressed**: AC-1, AC-2, AC-3, AC-4
- **Test Requirements**:
  - `rule` TR-2.1: `冒泡排序流程图.png` 存在，且 Pillow 重新读取宽高 > 0
  - `rule` TR-2.2: 图中包含 FR-3 全部 9 类逻辑节点且文字正确
  - `rubric` TR-2.3: 控制流正确性；scale 1-5；anchors 1/3/5 同 AC-3；threshold >= 4；evidence 为目视核对
  - `rubric` TR-2.4: 可读性；scale 1-5；anchors 1/3/5 同 AC-4；threshold >= 4；evidence 为目视核对
- **Notes**: R1 审查发现 PNG 从工作区丢失（Review R1 F-1），已用非沙箱方式重新写入真实文件系统并复验。
- **Completion Evidence**:
  - TR-2.1: `Get-Item` 显示文件真实存在、71366 字节；`Image.open()` 输出 `REOPEN OK (2000, 2080) RGB`；Glob 工具可见 [冒泡排序流程图.png](file:///d:/vscode/c_practice/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F%E6%B5%81%E7%A8%8B%E5%9B%BE.png)。
  - TR-2.2: 自评 pass。重建图目视核对 11 个节点全部存在且文字正确：开始、输入数组 a（长度为 n）、i=0、i<n-1、j=0、j<n-1-i、a[j]>a[j+1]、交换 a[j] 与 a[j+1]、j=j+1、i=i+1、结束。
  - TR-2.3: 自评 5/5。三组判断的是/否走向正确；j 回边从左侧返回内层菱形、i 回边从右侧返回外层菱形右下缘；两处跨线有过桥弧。
  - TR-2.4: 自评 5/5。标准符号、纵向对齐、箭头带尖、微软雅黑中文无乱码，2 倍渲染清晰，深蓝/浅橙配色统一。
  - 说明：以上自评分须以 Review R2 独立复核为最终依据。

## Issue I-1: 重建缺失的绘制脚本与 PNG 产物
- **Status**: `completed`
- **Priority**: high
- **Depends On**: None
- **Discovered By**: Review R1（F-1、F-2）
- **Description**:
  - R1 独立审查确认 `draw_bubble_flowchart.py` 与 `冒泡排序流程图.png` 在工作区均不存在，Image.open 返回 FileNotFoundError。
  - 需重新编写脚本并生成 PNG 到 spec 指定路径 d:\vscode\c_practice\冒泡排序流程图.png。
- **Acceptance Criteria Addressed**: AC-1, AC-2, AC-3, AC-4
- **Test Requirements**:
  - `rule` TR-I-1.1: 两个文件在工作区真实存在（Glob/目录列举可见），脚本运行退出码 0
  - `rule` TR-I-1.2: `Image.open(r"...冒泡排序流程图.png")` 成功且宽高 > 0
  - `rubric` TR-I-1.3: 控制流与可读性；scale 1-5；anchors 同 AC-3/AC-4；threshold >= 4；evidence 为新一轮独立审查目视
- **Completion Evidence**:
  - TR-I-1.1: Glob 同时列出 `draw_bubble_flowchart.py` 与 `冒泡排序流程图.png`；脚本退出码 0。
  - TR-I-1.2: `REOPEN OK (2000, 2080) RGB`，文件长度 71366 字节。
  - TR-I-1.3: 自评 5/5，等待 Review R2 独立确认。

## Issue I-2: 以真实输出重写完成证据
- **Status**: `completed`
- **Priority**: medium
- **Depends On**: Issue I-1
- **Discovered By**: Review R1（F-3）
- **Description**:
  - 原 Task 1/2 的 Completion Evidence 与仓库实际状态矛盾，需在产物重建后以本次真实命令输出与目视结果重写，不允许保留无法复现的旧证据。
- **Acceptance Criteria Addressed**: AC-1
- **Test Requirements**:
  - `rule` TR-I-2.1: tasks.md 中每条完成证据都能对应到本次实际执行的命令输出或现存文件路径
- **Completion Evidence**:
  - TR-I-2.1: 本文件所有 Completion Evidence 均为 2026-09-24 本次重建实际产生的命令输出（"已保存 (2000, 2080)"、"REOPEN OK"、71366 字节）与现存文件链接，旧的不可复现证据已删除。
