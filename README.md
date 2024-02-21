# Библиотека с длинной арифметикой

# Сборка

Для тестирования используется открытый репозиторий GoogleTests

# Примерный вид сборки
```bash
git clone --recurse-submodules https://github.com/toxabrat/Big_Number.git
cd Big_Number
mkdir cmake_build
cd cmake_build
cmake ..
cmake --build .
```

# Установка библиотеки тестирования
```bash
cd tests
cd googletest
git clone https://github.com/google/googletest.git googletest
```

# Тестирование
```bash
./tests/tests
```
