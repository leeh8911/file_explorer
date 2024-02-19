# Architecture

```plantuml
@startuml

package Model {
    component Repository
    component FileSystem
    component Worker
}
package View {
    InputWindow
    OutputWindow
}
package Controller {
    Search
}

@enduml
```

- Model : 도메일 영역에 해당하며, 비즈니스 로직을 처리하는 패키지
- View : 시각화 역할을 담당하는 패키지
- Controller : 제어 역할을 담당하는 패키지

Controller에서 수행을 요청하면, Model에서는 해당 작업을 처리하여 View 로 전달해준다.

## Usecase
