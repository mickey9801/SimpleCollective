# SimpleCollective DIY 牙籤總距杆

以 Arduino Leonardo 或 Arduino Micro 來製作簡單的牙籤直升機總距杆，讓大家即使用 Xbox 控制器來《 Microsoft Flight Simulator (MSFS2020) 》駕駛直升機仍能有較好的操控。

[下載 Airbus H135 直升機 Add-On](https://flightsim.to/file/8970/airbus-h135-helicopter-project)

## 影片介紹

[![PCM Gadget Live 牙籤總距杆介紹](https://github.com/mickey9801/SimpleCollective/blob/bf45e51b0b2da530d98e2a77a506ce3b3cb99e91/video-02.jpg)](https://youtu.be/_iHSxeVn-JA?t=764s "PCM Gadget Live 牙籤總距杆介紹")

## 零件表

- Arduino Leonardo 或 Arduino Micro 1 塊
- 50k 或 100k Ohm 電位器（可變電阻） 1 個
- 杜邦線 3 條
- 迷你麵包板 1 塊

## 開發軟件

- [Arduino IDE](https://www.arduino.cc/en/software) 。撰文時的版本為 1.8.15 。
- 由 MHeironimus 開發的 [Arduino Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary/releases) （詳情參閱下文）

## 電路圖

<a href="https://github.com/mickey9801/SimpleCollective/blob/main/arduino_collective.jpg"><img src="https://github.com/mickey9801/SimpleCollective/blob/main/arduino_collective.jpg" style="width:300px"></a>

## 製作說明

要令 Arduino Leonardo / Micro 變成 USB 遊戲控制器，需要[由 MHeironimus 開發的 Arduino Joystick Library](https://github.com/MHeironimus/ArduinoJoystickLibrary/releases) ，但這個函式庫沒有登錄到 Arduino 的官方 Library Manager ，所以大家要下載「 Source Code (zip) 」檔案，並將它匯入 Arduino IDE ，就能順利將程式編譯上載到 Arduino 開發板。撰文時 Arduino Joystick Library 的版本為 2.0.7 。

1. 將 Arduino Leonardo / Micro 以 micro USB 線連接到電腦，開啟 Arduino IDE ，
2. 以 Arduino IDE 開啟 Collective.ino 檔案
3. 在 Arduino IDE 的主選單中選「 Sketch ＞ Include Library ＞ Add .ZIP Library 」，然後選擇下載回來的「 ArduinoJoystickLibrary-2.0.7.zip 」檔案將它匯入。
4. 按工具列左上角的「 Verify 」鍵來檢查程式有沒有問題，或者直接按旁邊的「 Upload 」鍵將它上載到 Arduino Leonardo / Micro 。

## 調校控縱角度

完成編譯和上載後，基本上已可以在 MSFS2020 裡使用這支牙籤總距杆，不過由於電位器的旋轉約有 280º ，用起來會較不就手，縮減一下電位器的可用旋轉範圍會較好用（當然這會減低總距杆的靈敏度，但旋轉 60º 基本上也夠用的）。

1. 修改程式第 10 行，設定為 `ture` 以輸出電位器讀數，然後將程式編譯上載到開發板。
   
   ```c
   bool printVals = true; // 輸出電位器讀數
   ```

2. 在連接著 Arduino Leonardo / Micro 時，開啟 Arduino IDE 的「 Tools ＞ Serial Monitor 」，將電位器扭到你覺得適合的起始角度（總距杆最低的位置），抄下 Serial Monitor 左邊欄位的讀數（本例中是 336 ）。
3. 接著扭到結束角度（總距杆最高的位置），抄下 Serial Monitor 左邊欄位的讀數（本例中是 500 ）。
4. 修改程式第 7 行，以抄下的讀數取代 0 和 1023 兩個數值。

    ```c
    int axisLimits0[] = {336, 500}; // 數值僅供參考，請自行測試讀取。
    ```

5. 將程式編譯上載到開發板，測試一下效果。
6. 滿意操縱角度的話就可以將第 10 行設回 `false` 再編譯上傳到開發板就完成。

## 將牙籤總距杆加到 MSFS2020

大家只要登入 MSFS2020 ，按「 Options ＞ Controls 」就可以發現多了「 Arduino Leonardo / Micro 」這個控制器，接著就要將完成的牙籤總距杆綁定到「 Throttle Axis （油閥軸）」即可使用。

1. 在左邊「 Search 」欄位輸入 `throttle axis`，並在中間欄點擊中間的灰格；
2. 點擊介面最頂一欄，然後扭動牙籤總距杆， MSFS2020 就會自動讀取到牙籤總距杆是「 Joystick Slider X 」。按「 VALIDATE 」確認設定；
3. 設定任意名字來建立新控制器 Profile ，按 OK 完成設定；
4. 可以扭動一下牙籤總距杆看看 Throttle Axis 的白條有沒有移動。如果發覺方向相反的話，可以勾選左邊的「 REVERSE AXIS 」倒轉操控。測試完成後按「 F11 」即可儲存設定。
