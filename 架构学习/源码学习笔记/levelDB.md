# [LevelDB](https://hardcore.feishu.cn/docs/doccnqc6VrpZk2JXSTcNr3Pq7Eb)

## 高级数据结构

1. 跳表
   
2. 布隆过滤器
3. SST(sorted string table)结构
   
## C++语法

1. 内存对齐关键字 aligned_storage<sizeof(T), alignof(T)>;

2. mmap内存映射，减少一次内存拷贝，原因是mmap将文件直接映射到用户空间，减少了一次文件到内核空间的拷贝;

## googleTest使用说明

### [解读TEST_F宏](https://wenku.baidu.com/view/39b27341a75177232f60ddccda38376baf1fe090.html)


### 单元测试

1. 以函数为单位；
2. 以类进行测试；

EXPECT_XXX:不合期望会继续往下执行；
ASSERT_XXX：不合期望会不会继续往下执行，直接退出；

g++ sample1.cc sample1_unittest.cc -o sample1 -lpthread -lgtest -std=c++11 -lgtest_main

### gtest事件机制

1. testcase事件

```c++
//NOTE: testcase事件：每个案例执行前后执行。如会在每个TEST_F前后分别执行SetUp和TearDown
class CaseTestSmpl: public testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_F(CaseTestSmpl, testTrue) {
    //TODO: test code1
}

TEEST_F(CaseTestSmpl, testFalse) {
    //TODO: test code2
}
```

2. testsuite事件

```c++
//NOTE: Testsuite事件：在某一批案例中，第一个用例执行前，执行SetUpTestCase到最后一个用例执行后，执行TearDownTestCase。如SuiteTestSmpl的SetUpTestCase和TearDownTestCase会在下面的TEST_F系列函数执行前后执行一次。
class SuiteTestSmpl : public testing::Test {
protected:
    static void SetUpTestCase() {
        //TODO: do init things
    }

    static void TearDownTestCase() {
        //TODO: do destroy things
    }
};

TEST_F(SuiteTestSmpl, test_1th) {
    //TODO: test case 1
}
TEST_F(SuiteTestSmpl, test_2th) {
    //TODO: test case 2
}
TEST_F(SuiteTestSmpl, test_3th) {
    //TODO: test case 3
}
TEST_F(SuiteTestSmpl, test_4th) {
    //TODO: test case 4
}
```

1. global事件

```c++
//NOTE: 继承Environment实现全局事件类，GlobalTestSmpl会在整个测试环境中存在，在环境初始化时调用SetUp，在return RUN_ALL_TESTS执行后调用TearDown。该类需要重写main函数使用AddGlobalTestEnvironment加载才生效。
class GlobalTestSmpl: public testing::Environment
{
    protected:
        //NOTE: 测试所有用例前执行
        virtual void SetUp() {
            //TODO: do init thing
        }
        //NOTE: 测试完所有用例后执行
        virtual void TearDown() {
            //TODO: do teardown thing
        }

        int _a; //NOTE:这个值再整个测试环境中有效
}

int _tmain(int argc, char* argv[]) {
    testing::AddGlobalTestEnvironment(new GlobalTestSmpl);//NOTE: 注册全局事件类
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

### 如何选择事件机制

1. 生命周期；

#### 死亡测试
