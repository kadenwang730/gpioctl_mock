# 🧪 gpioctl_mock – 模擬 GPIO 控制工具（for Linux）

這是一個使用 C 語言撰寫的模擬 GPIO 控制工具，模擬 Linux 系統中 `/sys/class/gpio` 的行為。  
即使在沒有實體 GPIO 硬體的虛擬機（如 VirtualBox）中，也能體驗 GPIO 控制流程。

> 📚 本工具適合學習嵌入式 Linux 的新手、正在準備嵌入式軟體工程師面試者使用。

---

## 🎯 目標與學習重點

- 練習用 C 語言控制硬體資源（透過檔案系統）
- 熟悉 Linux GPIO 操作流程：`export → direction → value`
- 體驗 CLI 控制工具撰寫方式
- 可作為轉職履歷作品集展示

---

## 📁 專案結構

```
gpioctl_mock/
├── gpioctl_mock.c         # 主程式
├── Makefile               # 編譯設定
└── mock_sys/              # 模擬的 GPIO 檔案系統
    └── class/
        └── gpio/
            ├── export
            └── gpio24/
                ├── direction
                └── value
```

---

## 🧪 功能對照

| 指令                         | 功能說明                          |
|------------------------------|-----------------------------------|
| `./gpioctl_mock -w 24 1`     | 將 GPIO 24 設為輸出並寫入值 1     |
| `./gpioctl_mock -r 24`       | 讀取 GPIO 24 的模擬電位值         |

---

## 🚀 使用方式

### 1️⃣ 建立模擬 GPIO 環境

```bash
mkdir -p mock_sys/class/gpio/gpio24
echo "24" > mock_sys/class/gpio/export
echo "out" > mock_sys/class/gpio/gpio24/direction
echo "0" > mock_sys/class/gpio/gpio24/value
```

---

### 2️⃣ 編譯程式

```bash
make
```

---

### 3️⃣ 執行範例

```bash
./gpioctl_mock -w 24 1
# Output: GPIO 24 set to 1

./gpioctl_mock -r 24
# Output: GPIO value: 1
```

---

## 📦 Makefile 支援指令

```bash
make        # 編譯程式
make clean  # 移除執行檔
```

---

## 🔧 延伸功能（建議未來可加入）

- [ ] 支援 `unexport` 功能
- [ ] 支援多個 GPIO 編號
- [ ] 改為傳入 `mock_sys` 路徑參數
- [ ] 加入自動化測試機制（ex: assert GPIO 值）

---

## 🧑‍💻 作者

Chris Wang  
🔧 軟體工程師轉職中，目標為嵌入式與軟韌體開發  
📫 此專案為學習與作品集實作之一

---

## 📜 License

MIT License
