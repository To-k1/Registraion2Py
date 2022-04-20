# 使用前请把 *refImg.png* 放到工作目录,把 *registration_py.pyd* 放到python目录
# 类 Registrator 
## 该类继承自 *Qbject* ,可以使用 *moveToThread()* 方法
## 创建方法
```python
import registration_py

registrator = registration_py.Registrator()

```

## 普通成员函数
### isPaused() -> bool
- 用于查看配准程序是否暂停，若暂停返回true
- 例子
```python
if registrator.isPaused():
    print("已暂停")

```
### worker_pause() -> void
- 用于使程序暂停,调用后使registrator内的私有变量is_paused置为true,使程序在配准完目前这张图后暂停

### worker_resume() -> void
- 用于使程序继续,调用后使registrator内的私有变量is_paused置为false


## 槽函数(slots)
### Registrating(str srcPattern, str binPattern, str dstPattern, str useSemiAuto, str useFailedImg, int startPos) -> void
- 实现配准功能
- 用于绑定开始进行配准的信号函数,也可直接使用
- 例子
```python

import registration_py

#原图目录
srcPattern = "F:\\shixi\\CS\\registration\\registration\\srcImg"
#根箱轮廓二值图目录
binPattern = "F:\\shixi\\CS\\registration\\registration\\binImg"
#配准完成图片的存放目录
dstPattern = "F:\\shixi\\CS\\registration\\registration\\dstImg"
#是否使用手动配准[y/n]
useSemiAuto = 'n'
#是否使用失败文件列表[y/n]
useFailedImg = 'n'
#从第几个图片开始，用于暂停后的恢复
startPos = 0

registrator = registration_py.Registrator()
registrator.Registrating(srcPattern, binPattern, dstPattern, useSemiAuto, useFailedImg, startPos)

```

## 信号函数(signals)
### HandleResults() -> void
- 用于绑定完成所有图片配准后需要进行的操作对应的槽函数

### HandlePause() -> void
- 用于绑定暂停后需要进行的操作对应的槽函数

### SendProcess(str processingName, int processingNum, int allNum) -> void
- 用于绑定每个图片配准完成后需要进行的在界面上显示进度的操作对应的槽函数
- processingName为正在处理的文件名
- processingNum为正在处理的是第几个图片
- allNum为总图片数

# 如何用信号槽使其工作
- 将其绑定到一个线程上，再用信号函数绑定 *registrating()* 方法, 再开始该线程, 并调用与 *registrator.registration()* 绑定的信号函数
- 例子
```python
myThread = QThread()
registrator.moveToThread(myThread)
```


# 如何实现暂停和恢复
## 暂停
- 使用 *worker_pause()* 后，程序会暂停，此时的进度会留在GUI的文本框中
- 终止 *registrator* 绑定的线程
- 进行GUI的改变
## 恢复
- 重启 *registrator* 绑定的线程
- 从GUI文本框中读取目前的进度作为startPos参数来调用与 *registrator.registration()* 绑定的信号函数,其他参数和开始运行时相同