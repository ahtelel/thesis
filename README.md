# Sử dụng thiết bị thí nghiệm (thầy Chất)

Ví dụ cách lắp một cổng quang (LED phát nối trở 330 ohm):
![](https://media.discordapp.net/attachments/467378202575241244/769147726712930334/image0.jpg)

Code đang sử dụng: https://github.com/ahtelel/thesis/blob/main/1Photogate.ino 

Ví dụ dữ liệu sẽ hiện ra trên Serial Monitor (Nếu dùng Serial Plotter thì chắc chắn sẽ chỉ ra một đường thẳng)
![](https://cdn.discordapp.com/attachments/467378202575241244/769141206793584690/unknown.png)

Phương trình sóng dừng và sơ đồ lắp cổng quang lý tưởng:
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
- Cổng quang sẽ có cấu tạo như thế nào? (Lắp vào bo mạch trắng rồi dựng lên hay thọc qua hộp carton để trang trí (lmao) ?)
- Có ý tưởng thêm hay chỉnh sửa hay bớt gì thì mọi người thoải mái cùng nhau xây dựng =]
## Chia việc:
- HA: Coder + Lắp mạch + BOSS
- 1 designer + 1 đứa cùng designer xem có mua được 'cái đứa designer bảo cần' không
- 1 người ghi lại thu chi etc. (Có thể không cần vì HA sẽ mua đồ hết?)
- Bây giờ thì mọi người vẽ mô hình (hoặc mua đồ về lắp luôn) cái hệ thống cổng quang gồm ~~9343294320184~~ số lẻ cổng quang (khoảng 7 -> 13) để có cái đề trình bày với thầy Chất
- Và hoàn thành cái bài dùng MIT App Inventor tuần trước nữa (thầy bảo mỗi đứa phải thuyết trình + cho thầy xem được app của mình hiện được số, rồi thầy sẽ xem mạch, động tay vào cảm biến etc.)
