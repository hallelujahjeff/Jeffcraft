### 简介
***
- 一个仿照Minecraft的Voxel Game，由C++ / OpenGL编写
- 实现了地形生成、方块的破坏与放置、物理碰撞、以及简单的照明系统和昼夜交替
- 项目结构以及部分实现参考了https://github.com/Hopson97/MineCraft-One-Week-Challenge


### 实现细节
***
#### 1. 大规模方块的渲染
1.  将16 * 16 * 16个方块作为一个Chunk，每次以Chunk为最小单位渲染
2. 被遮挡的方块的面不进行渲染
3. 反面剔除 / 视锥体剔除
4. 每次只渲染玩家周围一定范围的方块

#### 2. 地形生成
-  使用柏林噪声(Perlin noise)生成高度图与生物群落图，再批量放置方块

#### 3.物理碰撞
- 简单的AABB包围盒检测

#### 4.光照
点光源使用BFS进行传播。
记录每个方块的光照强度，以顶点数据的形式传给片段着色器。

#### 5.音乐
- 使用第三方库SFML

![image](https://user-images.githubusercontent.com/32906436/110504614-4de5f580-8138-11eb-9575-75b4535bbb0f.png)
![image](https://user-images.githubusercontent.com/32906436/110504644-56d6c700-8138-11eb-9f7c-7fbd01357de9.png)
