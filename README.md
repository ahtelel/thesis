# Sử dụng thiết bị thí nghiệm trong dạy học Vật lí

![Link album ảnh - clip thí nghiệm](https://www.facebook.com/media/set/?vanity=ahtelel7&set=a.1510228082482550)

Ví dụ cách lắp một cổng quang (LED phát nối trở 330 ohm):
![](https://media.discordapp.net/attachments/467378202575241244/769147726712930334/image0.jpg)

![Code đang sử dụng cho 1 cổng quang](https://github.com/ahtelel/thesis/blob/main/1Photogate.ino)

Ví dụ dữ liệu sẽ hiện ra trên Serial Monitor với code 1 cổng quang: (Nếu dùng Serial Plotter thì chắc chắn sẽ ra một đường thẳng)
![](https://cdn.discordapp.com/attachments/467378202575241244/769141206793584690/unknown.png)

Ví dụ cách lắp hai cổng quang (LED phát nối trở 330 ohm):
![](https://cdn.discordapp.com/attachments/467378202575241244/770133032039612426/image0.jpg)

![Code đang sử dụng cho 2 cổng quang](https://github.com/ahtelel/thesis/blob/main/2Photogate.ino)

Ví dụ dữ liệu sẽ hiện ra trên Serial Monitor với code 2 cổng quang:
![](https://cdn.discordapp.com/attachments/467378202575241244/770137615260581898/unknown.png)

###### Phương trình sóng dừng và sơ đồ lắp cổng quang lý tưởng:
![](https://media.discordapp.net/attachments/467378202575241244/769147105557741578/image0.jpg)
- Lắp nhiều cổng quang chồng lên nhau, các LED thu sẽ được nối với các cổng khác nhau (sẽ được phản ánh trên code)
- Mỗi LED thu sẽ cho trước một giá trị của x 

## Những vấn đề cần giải quyết:
###### Về mạch:
- Mỗi cổng quang sẽ đo gì / đưa vào Arduino dữ liệu nào?
- Những dữ liệu nào cần được cho trước (làm hằng số trong code?)
###### Về thiết kế: (dùng với bộ sóng dừng Mỹ PASCO)
***Ý tưởng thiết kế của HA***
![](https://cdn.discordapp.com/attachments/467378202575241244/769154062347272242/image0.jpg)
- Cổng quang sẽ có cấu tạo như thế nào? (Lắp vào bo mạch trắng rồi dựng lên / núm vặn để đưa cổng quang lên xuống để căn chuẩn cổng x0)
- Có ý tưởng thêm hay chỉnh sửa hay bớt gì thì mọi người thoải mái cùng nhau xây dựng
## Chia việc:
- HA: Coder + Lắp mạch + Leader
- 5 designers + background knowledge gatherer
- Bây giờ thì mọi người vẽ mô hình (hoặc mua đồ về lắp luôn) cái hệ thống cổng quang gồm số lẻ cổng quang (khoảng 7 -> 13) để có cái đề trình bày với thầy Chất
- Và hoàn thành cái bài dùng MIT App Inventor tuần trước nữa (thầy bảo mỗi đứa phải thuyết trình + cho thầy xem được app của mình hiện được số, rồi thầy sẽ xem mạch, động tay vào cảm biến etc.
