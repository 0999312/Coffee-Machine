# Coffee-Machine
高级程序语言设计课程设计项目——咖啡机模拟程序
要编译的是src/CoffeeMachine.cpp

```mermaid
graph LR

A(Start)

A --> B[Look for an item]

B --> C{Did you find it?}
C -->|Yes| D(Stop looking)
C -->|No| E{Do you need it?}
E -->|Yes| B
E -->|No| D
```
