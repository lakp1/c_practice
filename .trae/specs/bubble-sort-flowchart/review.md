# 冒泡排序流程图 - 独立审查

- [x] CP-R1: PNG 文件存在且可正常打开、尺寸非零
  - **Type**: `rule`
  - **Covers**: AC-1 / TR-2.1
  - **Evidence**: R2 实测 `Get-Item` = 71366 字节；`Image.open()` 输出 (2000, 2080) RGB → **pass**

- [x] CP-R2: FR-3 全部逻辑节点齐全且文字正确
  - **Type**: `rule`
  - **Covers**: AC-2 / TR-1.x、TR-2.2
  - **Evidence**: R2 目视逐一核对 11 个节点（开始、输入数组a(长度n)、i=0、i<n-1、j=0、j<n-1-i、a[j]>a[j+1]、交换、j=j+1、i=i+1、结束）全部存在且文字正确，符号类型正确 → **pass**

- [x] CP-U1: 算法控制流表达准确（分支、是/否标签、两层循环回边）
  - **Type**: `rubric`
  - **Covers**: AC-3 / TR-2.3
  - **Scale**: 1-5
  - **Anchors**: 1 = 分支或循环方向错误；3 = 主逻辑正确但个别回边/标签不清晰；5 = 所有判断分支、是/否标签、两层循环回边均准确无歧义
  - **Pass Threshold**: >= 4
  - **Evidence**: R2 评分 **4/5（达到阈值）**。三组判断分支与 6 个是/否标签全部正确；两条循环回边方向正确、分走左右独立轨道；两处跨线有过桥弧。未满分原因：外层回边从菱形边中点而非顶点进入（advisory F-2），无歧义。

- [x] CP-U2: 图形规范与可读性（标准符号、对齐、中文无乱码、无歧义交叉）
  - **Type**: `rubric`
  - **Covers**: AC-4 / TR-1.2、TR-2.4
  - **Scale**: 1-5
  - **Anchors**: 1 = 符号混用、文字乱码、箭头交叉混乱；3 = 内容可辨但排版粗糙；5 = 标准符号、对齐整齐、中文清晰、箭头不交叉/跨线有标识
  - **Pass Threshold**: >= 4
  - **Evidence**: R2 评分 **4/5（达到阈值）**。标准符号、微软雅黑中文无乱码、2 倍渲染锐利、配色统一；几何小瑕疵见 advisory F-1/F-3。

## Review History

### Review R1
- **Result**: `fail`
- **Evidence**: 独立审查员（全新只读上下文）穷举文件系统与 git 全历史确认：`d:\vscode\c_practice\冒泡排序流程图.png` 与 `d:\vscode\c_practice\draw_bubble_flowchart.py` 均不存在；`Image.open()` 返回 FileNotFoundError。CP-R1 fail；CP-R2/CP-U1/CP-U2 blocked（无图可检）。tasks.md 原有完成证据与仓库实际状态矛盾。
- **Findings**:
  - F-1: `actionable`，blocker；交付 PNG 缺失（FR-1/AC-1 不满足）→ 见 Issue I-1
  - F-2: `actionable`，blocker；绘制脚本缺失，产物不可重建 → 见 Issue I-1
  - F-3: `actionable`，high；tasks.md 完成证据与实际状态不符 → 修复后以真实命令输出重写证据，见 Issue I-2

### Review R2
- **Result**: `pass`
- **Evidence**: 全新只读审查员（Agent 537b51ad）独立复核。命令实测：文件真实存在、71366 字节、`Image.open()` = (2000, 2080) RGB；Read 目视 11 节点齐全、控制流正确、符号规范、中文无乱码；另做像素级核验确认干线连续与两处过桥弧。CP-R1 pass、CP-R2 pass、CP-U1 4/5、CP-U2 4/5，均达标。R1 的 F-1/F-2/F-3 全部关闭（Issue I-1、I-2 completed）。
- **Findings（均为 advisory，不阻塞验收）**:
  - F-1: `advisory`，low；外层回边水平段 y=415 与"结束"胶囊底边重合，视觉贴线，建议下移 10–15px。
  - F-2: `advisory`，low；外层回边进入菱形边中点而非顶点；可改为进入右顶点并加汇合圆点。
  - F-3: `advisory`，low；j 汇合点附近有两个连续向下箭头，略显冗余。
- **Blocked By**: 无
