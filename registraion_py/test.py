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
