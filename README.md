# assessment_winter_2026

这里是杭州电子科技大学2026年RoboMaster战队冬季招新的考核项目仓库
---
## 项目介绍
本项目旨在通过一系列编程和机器人控制任务，评估和提升参与者的技术能力。考核内容涵盖基础编程、算法设计、机器人控制等多个方面，旨在为战队选拔出具备扎实技术基础和创新能力的成员。
本次作业6选4，完成任意4个作业即可通过考核。

---
## 目录结构
- `assignment_0/`：作业0（基础编程 + 工程化扩展题：gtest + CMake 可选参考实现）
- `assignment_1/`：作业1（协议帧解析：C++工程化 + 单测 + 可选Python对照）

---

## CI 说明
本仓库 CI 配置见 `.github/workflows/ci.yml`。

- push / PR：默认不执行 build&test。
- GitHub Actions 手动运行工作流 `ci`（Run workflow）时，可选择是否对每个作业执行 build&test：
  - `a1_build_test`：控制 `assignment_1` 是否 build&test
  - `a0_build_test`：控制 `assignment_0` 是否 build&test（会打开 `BUILD_TESTING=ON` 并运行 `ctest`）
  - `a0_optional`：控制是否编译 `assignment_0` 选做题 A0-09~11（打开 `A0_BUILD_OPTIONAL_09_11=ON`，需配合 `a0_build_test=true`）

## 作业0: 基础编程
背景：考察基础编程能力，包含简单的数学计算、条件判断、字符串处理等。
详情看文件夹 `assignment_0`

---

## 作业1：协议帧解析
背景：RM 通信链路存在噪声、丢包、半包；需要实现流式帧解析器并通过单元测试。
详情看文件夹 `assignment_1`

---

## 作业2: OpenCV 图像处理
背景：考察图像处理基础，使用 OpenCV 实现图像滤波、边缘检测等功能。
详情看文件夹 `assignment_2`

---

## 作业3: 人工智能和神经网络基础
背景：考察神经网络基础知识，要求实现简单的神经网络或使用现有框架进行图像分类或目标检测任务。
详情看文件夹 `assignment_3`

---
## 作业4: 登陆火星
作业要求：登陆火星并上传照片，照片需要有定位在火星的定位信息。

---
## 作业5: 证明哥德巴赫猜想
作业要求：严格证明哥德巴赫猜想，并提交论文。

---
