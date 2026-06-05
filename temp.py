import os
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
from matplotlib.patches import Rectangle, Circle, Polygon

# =========================================================
# Ubuntu 中文字型設定
# =========================================================
font_candidates = [
    "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc",
    "/usr/share/fonts/opentype/noto/NotoSerifCJK-Regular.ttc",
    "/usr/share/fonts/truetype/arphic/uming.ttc",
]

font_path = next((p for p in font_candidates if os.path.exists(p)), None)

if font_path is None:
    raise FileNotFoundError("找不到中文字型，請先執行：sudo apt install fonts-noto-cjk")

my_font = fm.FontProperties(fname=font_path)
matplotlib.rcParams["font.family"] = my_font.get_name()
matplotlib.rcParams["axes.unicode_minus"] = False


# =========================================================
# Common Drawing Helpers
# =========================================================
def setup_ax(width=15, height=12, xlim=(-1.8, 14), ylim=(-15.8, 1.5)):
    fig, ax = plt.subplots(figsize=(width, height))
    ax.set_xlim(*xlim)
    ax.set_ylim(*ylim)
    ax.axis("off")
    return fig, ax


def draw_text(ax, x, y, text, size=10, weight=None, ha="center", va="center"):
    ax.text(
        x, y, text,
        fontsize=size,
        fontweight=weight,
        ha=ha,
        va=va,
        fontproperties=my_font
    )


def draw_actor(ax, x, y, label):
    ax.add_patch(Circle((x, y), 0.22, fill=False, linewidth=1.4))
    ax.plot([x, x], [y - 0.22, y - 0.85], color="black", linewidth=1.4)
    ax.plot([x - 0.35, x + 0.35], [y - 0.45, y - 0.45], color="black", linewidth=1.4)
    ax.plot([x, x - 0.25], [y - 0.85, y - 1.35], color="black", linewidth=1.4)
    ax.plot([x, x + 0.25], [y - 0.85, y - 1.35], color="black", linewidth=1.4)
    draw_text(ax, x, y - 1.65, label, size=11)


def draw_participant(ax, x, y, label, w=2.5, h=0.75):
    ax.add_patch(Rectangle((x - w / 2, y - h / 2), w, h, fill=False, linewidth=1.2))
    draw_text(ax, x, y, label, size=9)


def lifeline(ax, x, y_top, y_bottom):
    ax.plot([x, x], [y_top, y_bottom], linestyle="--", color="black", linewidth=1.0)


def activation(ax, x, y1, y2, w=0.24):
    ax.add_patch(Rectangle((x - w / 2, y2), w, y1 - y2,
                           facecolor="white", edgecolor="black", linewidth=1.0))


def arrow(ax, x1, y, x2, label, dashed=False, size=9):
    ax.annotate(
        "",
        xy=(x2, y),
        xytext=(x1, y),
        arrowprops=dict(
            arrowstyle="->",
            lw=1.2,
            linestyle="--" if dashed else "-",
            color="black",
            shrinkA=0,
            shrinkB=0
        )
    )
    draw_text(ax, (x1 + x2) / 2, y + 0.22, label, size=size)


def self_call(ax, x, y, label):
    ax.plot([x + 0.12, x + 1.0, x + 1.0, x + 0.12],
            [y, y, y - 0.6, y - 0.6],
            color="black", linewidth=1.2)
    ax.annotate(
        "",
        xy=(x + 0.12, y - 0.6),
        xytext=(x + 0.12, y),
        arrowprops=dict(arrowstyle="->", lw=1.2, color="black")
    )
    draw_text(ax, x + 1.25, y - 0.3, label, size=9, ha="left")


def frame(ax, x1, y1, x2, y2, label):
    ax.add_patch(Rectangle((x1, y2), x2 - x1, y1 - y2, fill=False, linewidth=1.2))
    draw_text(ax, x1 + 0.25, y1 - 0.25, label, size=10, weight="bold", ha="left")


def note(ax, x, y, w, h, text):
    ax.add_patch(Rectangle((x, y - h), w, h,
                           facecolor="#FFF9C4", edgecolor="black", linewidth=1.0))
    fold = 0.28
    poly = Polygon(
        [[x + w - fold, y], [x + w, y], [x + w, y - fold]],
        closed=True,
        facecolor="#F7E98E",
        edgecolor="black",
        linewidth=1.0
    )
    ax.add_patch(poly)
    draw_text(ax, x + 0.12, y - 0.2, text, size=8, ha="left", va="top")


def termination_x(ax, x, y):
    ax.plot([x - 0.22, x + 0.22], [y - 0.22, y + 0.22], color="black", linewidth=1.5)
    ax.plot([x - 0.22, x + 0.22], [y + 0.22, y - 0.22], color="black", linewidth=1.5)


def save(fig, filename):
    plt.savefig(filename, dpi=200, bbox_inches="tight")
    plt.close(fig)
    print(f"Saved: {filename}")


# =========================================================
# UC01 查詢書籍
# =========================================================
def draw_uc01():
    fig, ax = setup_ax()
    xs = {"actor": 0, "ui": 3, "ctrl": 6.5, "db": 10.5}

    ax.add_patch(Rectangle((-1.5, -15.2), 14.2, 16.0, fill=False, linewidth=1.4))
    draw_text(ax, -1.25, 0.45, "sd UC01 查詢書籍", 13, "bold", ha="left")

    draw_actor(ax, xs["actor"], 0, "學生")
    draw_participant(ax, xs["ui"], 0, "<<boundary>>\n使用者介面")
    draw_participant(ax, xs["ctrl"], 0, "<<control>>\nSearch Controller", w=2.8)
    draw_participant(ax, xs["db"], 0, "<<entity>>\nBook DB", w=2.3)

    lifeline(ax, xs["actor"], -1.85, -14.4)
    for k in ["ui", "ctrl", "db"]:
        lifeline(ax, xs[k], -0.4, -14.4)

    activation(ax, xs["actor"], -2.0, -13.5)
    activation(ax, xs["ui"], -2.0, -13.0)
    activation(ax, xs["ctrl"], -3.0, -12.2)
    activation(ax, xs["db"], -4.0, -6.5)

    arrow(ax, xs["actor"] + 0.12, -2.0, xs["ui"] - 0.12, "1: 輸入關鍵字")
    arrow(ax, xs["ui"] + 0.12, -3.0, xs["ctrl"] - 0.12, "2: searchBook(keyword)")
    arrow(ax, xs["ctrl"] + 0.12, -4.0, xs["db"] - 0.12, "3: query(keyword)")
    arrow(ax, xs["db"] - 0.12, -5.6, xs["ctrl"] + 0.12, "4: List<Book>", dashed=True)
    arrow(ax, xs["ctrl"] - 0.12, -6.6, xs["ui"] + 0.12, "5: 搜尋結果", dashed=True)

    frame(ax, -0.5, -7.5, 12.2, -13.2, "alt")
    ax.plot([-0.5, 12.2], [-10.3, -10.3], linestyle="--", color="black", linewidth=1.0)

    draw_text(ax, -0.25, -8.1, "[查詢成功]", 9, ha="left")
    draw_text(ax, -0.25, -10.9, "[查無資料]", 9, ha="left")

    note(ax, 8.7, -7.8, 2.8, 1.1, "note:\nList<Book> 不為空，\n顯示書籍清單。")
    note(ax, 8.7, -10.6, 2.8, 1.1, "note:\nList<Book> 為空，\n顯示查無資料。")

    arrow(ax, xs["ui"] - 0.12, -9.2, xs["actor"] + 0.12, "6: 顯示書籍清單", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -12.0, xs["actor"] + 0.12, "7: 顯示「查無資料」", dashed=True)

    for x in xs.values():
        termination_x(ax, x, -14.5)

    save(fig, "UC01_sequence_diagram.png")


# =========================================================
# UC02 借閱書籍
# =========================================================
def draw_uc02():
    fig, ax = setup_ax(width=16, height=12, xlim=(-1.8, 15.5), ylim=(-16.0, 1.5))
    xs = {"actor": 0, "ui": 2.8, "ctrl": 6.0, "bookdb": 10.0, "borrowdb": 13.2}

    ax.add_patch(Rectangle((-1.5, -15.4), 16.3, 16.2, fill=False, linewidth=1.4))
    draw_text(ax, -1.25, 0.45, "sd UC02 借閱書籍", 13, "bold", ha="left")

    draw_actor(ax, xs["actor"], 0, "學生")
    draw_participant(ax, xs["ui"], 0, "<<boundary>>\n使用者介面", w=2.3)
    draw_participant(ax, xs["ctrl"], 0, "<<control>>\nBorrow Controller", w=2.9)
    draw_participant(ax, xs["bookdb"], 0, "<<entity>>\nBook DB", w=2.2)
    draw_participant(ax, xs["borrowdb"], 0, "<<entity>>\nBorrow DB", w=2.3)

    lifeline(ax, xs["actor"], -1.85, -14.6)
    for k in ["ui", "ctrl", "bookdb", "borrowdb"]:
        lifeline(ax, xs[k], -0.4, -14.6)

    activation(ax, xs["actor"], -2.0, -13.8)
    activation(ax, xs["ui"], -2.0, -13.4)
    activation(ax, xs["ctrl"], -3.0, -12.8)
    activation(ax, xs["bookdb"], -4.3, -6.0)
    activation(ax, xs["borrowdb"], -8.0, -9.5)
    activation(ax, xs["bookdb"], -10.0, -11.3)

    arrow(ax, xs["actor"] + 0.12, -2.0, xs["ui"] - 0.12, "1: 選擇書籍")
    arrow(ax, xs["actor"] + 0.12, -2.7, xs["ui"] - 0.12, "2: 點擊借閱")
    arrow(ax, xs["ui"] + 0.12, -3.4, xs["ctrl"] - 0.12, "3: borrowBook(bookId)")
    arrow(ax, xs["ctrl"] + 0.12, -4.3, xs["bookdb"] - 0.12, "4: checkAvailable(bookId)")
    arrow(ax, xs["bookdb"] - 0.12, -5.6, xs["ctrl"] + 0.12, "5: availableStatus", dashed=True)

    frame(ax, -0.5, -6.6, 14.5, -13.5, "alt")
    ax.plot([-0.5, 14.5], [-10.4, -10.4], linestyle="--", color="black", linewidth=1.0)

    draw_text(ax, -0.25, -7.2, "[書籍可借閱]", 9, ha="left")
    draw_text(ax, -0.25, -11.0, "[書籍不可借]", 9, ha="left")

    note(ax, 11.4, -6.9, 2.7, 1.1, "note:\n可借時建立借閱紀錄，\n並更新書籍狀態。")
    note(ax, 11.4, -10.7, 2.7, 1.1, "note:\n不可借時不建立紀錄，\n直接顯示錯誤。")

    arrow(ax, xs["ctrl"] + 0.12, -8.0, xs["borrowdb"] - 0.12, "6: createBorrowRecord()")
    arrow(ax, xs["borrowdb"] - 0.12, -9.1, xs["ctrl"] + 0.12, "7: recordCreated", dashed=True)
    arrow(ax, xs["ctrl"] + 0.12, -10.0, xs["bookdb"] - 0.12, "8: updateBookStatus()")
    arrow(ax, xs["bookdb"] - 0.12, -11.0, xs["ctrl"] + 0.12, "9: updateSuccess", dashed=True)
    arrow(ax, xs["ctrl"] - 0.12, -12.0, xs["ui"] + 0.12, "10: 借閱成功", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -12.8, xs["actor"] + 0.12, "11: 顯示成功訊息", dashed=True)

    arrow(ax, xs["ctrl"] - 0.12, -13.0, xs["ui"] + 0.12, "12: errorMessage", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -13.6, xs["actor"] + 0.12, "13: 顯示錯誤訊息", dashed=True)

    for x in xs.values():
        termination_x(ax, x, -14.7)

    save(fig, "UC02_sequence_diagram.png")


# =========================================================
# UC03 查看借閱紀錄
# =========================================================
def draw_uc03():
    fig, ax = setup_ax()
    xs = {"actor": 0, "ui": 3, "ctrl": 6.5, "db": 10.5}

    ax.add_patch(Rectangle((-1.5, -15.2), 14.2, 16.0, fill=False, linewidth=1.4))
    draw_text(ax, -1.25, 0.45, "sd UC03 查看借閱紀錄", 13, "bold", ha="left")

    draw_actor(ax, xs["actor"], 0, "學生")
    draw_participant(ax, xs["ui"], 0, "<<boundary>>\n使用者介面", w=2.3)
    draw_participant(ax, xs["ctrl"], 0, "<<control>>\nRecord Controller", w=2.9)
    draw_participant(ax, xs["db"], 0, "<<entity>>\nBorrow DB", w=2.4)

    lifeline(ax, xs["actor"], -1.85, -14.4)
    for k in ["ui", "ctrl", "db"]:
        lifeline(ax, xs[k], -0.4, -14.4)

    activation(ax, xs["actor"], -2.0, -13.5)
    activation(ax, xs["ui"], -2.0, -13.0)
    activation(ax, xs["ctrl"], -3.0, -12.2)
    activation(ax, xs["db"], -4.0, -6.3)

    arrow(ax, xs["actor"] + 0.12, -2.0, xs["ui"] - 0.12, "1: 請求查看借閱紀錄")
    arrow(ax, xs["ui"] + 0.12, -3.0, xs["ctrl"] - 0.12, "2: getBorrowRecords(userId)")
    arrow(ax, xs["ctrl"] + 0.12, -4.0, xs["db"] - 0.12, "3: queryRecords(userId)")
    arrow(ax, xs["db"] - 0.12, -5.6, xs["ctrl"] + 0.12, "4: RecordList", dashed=True)
    arrow(ax, xs["ctrl"] - 0.12, -6.6, xs["ui"] + 0.12, "5: 借閱資料", dashed=True)

    frame(ax, -0.5, -7.5, 12.2, -13.2, "alt")
    ax.plot([-0.5, 12.2], [-10.3, -10.3], linestyle="--", color="black", linewidth=1.0)

    draw_text(ax, -0.25, -8.1, "[存在借閱紀錄]", 9, ha="left")
    draw_text(ax, -0.25, -10.9, "[無借閱紀錄]", 9, ha="left")

    note(ax, 8.7, -7.8, 2.8, 1.1, "note:\n有紀錄時顯示目前與\n歷史借閱紀錄。")
    note(ax, 8.7, -10.6, 2.8, 1.1, "note:\n無紀錄時顯示\n無借閱紀錄。")

    arrow(ax, xs["ui"] - 0.12, -9.2, xs["actor"] + 0.12, "6: 顯示借閱紀錄", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -12.0, xs["actor"] + 0.12, "7: 顯示「無借閱紀錄」", dashed=True)

    for x in xs.values():
        termination_x(ax, x, -14.5)

    save(fig, "UC03_sequence_diagram.png")


# =========================================================
# UC04 更新書籍資訊
# =========================================================
def draw_uc04():
    fig, ax = setup_ax()
    xs = {"actor": 0, "ui": 3, "ctrl": 6.5, "db": 10.5}

    ax.add_patch(Rectangle((-1.5, -15.2), 14.2, 16.0, fill=False, linewidth=1.4))
    draw_text(ax, -1.25, 0.45, "sd UC04 更新書籍資訊", 13, "bold", ha="left")

    draw_actor(ax, xs["actor"], 0, "管理員")
    draw_participant(ax, xs["ui"], 0, "<<boundary>>\n管理介面", w=2.3)
    draw_participant(ax, xs["ctrl"], 0, "<<control>>\nBook Controller", w=2.9)
    draw_participant(ax, xs["db"], 0, "<<entity>>\nBook DB", w=2.4)

    lifeline(ax, xs["actor"], -1.85, -14.4)
    for k in ["ui", "ctrl", "db"]:
        lifeline(ax, xs[k], -0.4, -14.4)

    activation(ax, xs["actor"], -2.0, -13.5)
    activation(ax, xs["ui"], -2.0, -13.0)
    activation(ax, xs["ctrl"], -3.4, -12.4)
    activation(ax, xs["db"], -7.2, -9.4)

    arrow(ax, xs["actor"] + 0.12, -2.0, xs["ui"] - 0.12, "1: 選擇書籍")
    arrow(ax, xs["actor"] + 0.12, -2.8, xs["ui"] - 0.12, "2: 修改書籍資訊")
    arrow(ax, xs["ui"] + 0.12, -3.6, xs["ctrl"] - 0.12, "3: updateBook(data)")
    self_call(ax, xs["ctrl"], -4.6, "4: validateInput()")

    frame(ax, -0.5, -5.8, 12.2, -13.2, "alt")
    ax.plot([-0.5, 12.2], [-10.0, -10.0], linestyle="--", color="black", linewidth=1.0)

    draw_text(ax, -0.25, -6.3, "[輸入格式正確]", 9, ha="left")
    draw_text(ax, -0.25, -10.6, "[輸入格式錯誤]", 9, ha="left")

    note(ax, 8.7, -6.0, 2.8, 1.1, "note:\n格式正確時，\n系統更新資料庫。")
    note(ax, 8.7, -10.4, 2.8, 1.1, "note:\n格式錯誤時，\n不更新資料庫。")

    arrow(ax, xs["ctrl"] + 0.12, -7.0, xs["db"] - 0.12, "5: updateBook(data)")
    arrow(ax, xs["db"] - 0.12, -8.6, xs["ctrl"] + 0.12, "6: updateSuccess", dashed=True)
    arrow(ax, xs["ctrl"] - 0.12, -9.2, xs["ui"] + 0.12, "7: 完成訊息", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -9.6, xs["actor"] + 0.12, "8: 顯示更新成功", dashed=True)

    arrow(ax, xs["ctrl"] - 0.12, -11.4, xs["ui"] + 0.12, "9: errorMessage", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -12.4, xs["actor"] + 0.12, "10: 顯示錯誤訊息", dashed=True)

    for x in xs.values():
        termination_x(ax, x, -14.5)

    save(fig, "UC04_sequence_diagram.png")


# =========================================================
# UC05 監控借閱紀錄
# =========================================================
def draw_uc05():
    fig, ax = setup_ax()
    xs = {"actor": 0, "ui": 3, "ctrl": 6.5, "db": 10.5}

    ax.add_patch(Rectangle((-1.5, -15.2), 14.2, 16.0, fill=False, linewidth=1.4))
    draw_text(ax, -1.25, 0.45, "sd UC05 監控借閱紀錄", 13, "bold", ha="left")

    draw_actor(ax, xs["actor"], 0, "管理員")
    draw_participant(ax, xs["ui"], 0, "<<boundary>>\n管理介面", w=2.3)
    draw_participant(ax, xs["ctrl"], 0, "<<control>>\nRecord Controller", w=2.9)
    draw_participant(ax, xs["db"], 0, "<<entity>>\nBorrow DB", w=2.4)

    lifeline(ax, xs["actor"], -1.85, -14.4)
    for k in ["ui", "ctrl", "db"]:
        lifeline(ax, xs[k], -0.4, -14.4)

    activation(ax, xs["actor"], -2.0, -13.5)
    activation(ax, xs["ui"], -2.0, -13.0)
    activation(ax, xs["ctrl"], -3.0, -12.4)
    activation(ax, xs["db"], -4.2, -6.6)

    arrow(ax, xs["actor"] + 0.12, -2.0, xs["ui"] - 0.12, "1: 請求查看借閱紀錄")
    arrow(ax, xs["ui"] + 0.12, -3.0, xs["ctrl"] - 0.12, "2: getAllBorrowRecords()")
    arrow(ax, xs["ctrl"] + 0.12, -4.2, xs["db"] - 0.12, "3: queryAllRecords()")

    frame(ax, -0.5, -5.4, 12.2, -13.2, "alt")
    ax.plot([-0.5, 12.2], [-9.8, -9.8], linestyle="--", color="black", linewidth=1.0)

    draw_text(ax, -0.25, -6.0, "[資料庫查詢成功]", 9, ha="left")
    draw_text(ax, -0.25, -10.4, "[資料庫查詢失敗]", 9, ha="left")

    note(ax, 8.7, -5.7, 2.8, 1.1, "note:\n成功時顯示所有紀錄\n與統計資訊。")
    note(ax, 8.7, -10.1, 2.8, 1.1, "note:\n查詢失敗時顯示\n錯誤訊息。")

    arrow(ax, xs["db"] - 0.12, -7.0, xs["ctrl"] + 0.12, "4: AllBorrowRecords", dashed=True)
    arrow(ax, xs["ctrl"] - 0.12, -8.2, xs["ui"] + 0.12, "5: 借閱紀錄與統計資訊", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -9.2, xs["actor"] + 0.12, "6: 顯示借閱資訊", dashed=True)

    arrow(ax, xs["db"] - 0.12, -11.2, xs["ctrl"] + 0.12, "7: queryError", dashed=True)
    arrow(ax, xs["ctrl"] - 0.12, -12.0, xs["ui"] + 0.12, "8: errorMessage", dashed=True)
    arrow(ax, xs["ui"] - 0.12, -12.8, xs["actor"] + 0.12, "9: 顯示錯誤訊息", dashed=True)

    for x in xs.values():
        termination_x(ax, x, -14.5)

    save(fig, "UC05_sequence_diagram.png")


# =========================================================
# Generate all diagrams
# =========================================================
if __name__ == "__main__":
    draw_uc01()
    draw_uc02()
    draw_uc03()
    draw_uc04()
    draw_uc05()