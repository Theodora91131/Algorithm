import os
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
from matplotlib.patches import Rectangle, FancyBboxPatch

# =========================
# Ubuntu 中文字型設定
# =========================
font_candidates = [
    "/usr/share/fonts/opentype/noto/NotoSansCJK-Regular.ttc",
    "/usr/share/fonts/opentype/noto/NotoSerifCJK-Regular.ttc",
]

font_path = next((p for p in font_candidates if os.path.exists(p)), None)

if font_path is None:
    raise FileNotFoundError("找不到中文字型，請先執行：sudo apt install fonts-noto-cjk")

my_font = fm.FontProperties(fname=font_path)
matplotlib.rcParams["font.family"] = my_font.get_name()
matplotlib.rcParams["axes.unicode_minus"] = False

fig, ax = plt.subplots(figsize=(15, 10))
ax.set_xlim(-8, 8)
ax.set_ylim(-8, 5)
ax.axis("off")

def text(x, y, s, size=10, weight=None, ha="center", va="center"):
    ax.text(x, y, s, fontsize=size, fontweight=weight,
            ha=ha, va=va, fontproperties=my_font)

def box(x, y, w, h, label, fill="#FFFFFF", rounded=False):
    if rounded:
        p = FancyBboxPatch(
            (x - w/2, y - h/2), w, h,
            boxstyle="round,pad=0.08,rounding_size=0.12",
            linewidth=1.2,
            edgecolor="black",
            facecolor=fill
        )
    else:
        p = Rectangle(
            (x - w/2, y - h/2), w, h,
            linewidth=1.2,
            edgecolor="black",
            facecolor=fill
        )
    ax.add_patch(p)
    text(x, y, label, size=9)

def arrow(x1, y1, x2, y2, label="", dashed=False):
    ax.annotate(
        "",
        xy=(x2, y2),
        xytext=(x1, y1),
        arrowprops=dict(
            arrowstyle="->",
            lw=1.3,
            linestyle="--" if dashed else "-",
            color="black",
            shrinkA=5,
            shrinkB=5
        )
    )
    if label:
        text((x1+x2)/2, (y1+y2)/2 + 0.25, label, size=8)

# =========================
# Title
# =========================
text(0, 4.3, "線上圖書館系統 System Architecture", size=16, weight="bold")

# =========================
# Layer Frames
# =========================
box(0, 2.6, 14, 1.5, "Presentation Layer（表現層）", fill="#E3F2FD", rounded=True)
box(0, 0.2, 14, 2.4, "Application Layer（應用邏輯層）", fill="#E8F5E9", rounded=True)
box(0, -3.0, 14, 1.8, "Data Layer（資料層）", fill="#FFF3E0", rounded=True)

# =========================
# Actors
# =========================
box(-6.2, 4.0, 2.0, 0.7, "學生\nStudent", fill="#FFFFFF")
box(6.2, 4.0, 2.0, 0.7, "管理員\nAdmin", fill="#FFFFFF")

# =========================
# UI Layer
# =========================
box(-3.2, 2.35, 2.8, 0.8, "Student Web UI", fill="#FFFFFF")
box(3.2, 2.35, 2.8, 0.8, "Admin Web UI", fill="#FFFFFF")

# =========================
# Application Layer Components
# =========================
box(-4.8, 0.35, 2.5, 0.8, "Search\nController", fill="#FFFFFF")
box(-1.6, 0.35, 2.5, 0.8, "Borrow\nController", fill="#FFFFFF")
box(1.6, 0.35, 2.5, 0.8, "Record\nController", fill="#FFFFFF")
box(4.8, 0.35, 2.5, 0.8, "Book\nController", fill="#FFFFFF")
box(0, -0.75, 2.7, 0.8, "Auth Service\n登入驗證", fill="#FFFFFF")

# =========================
# Data Layer
# =========================
box(-3.8, -3.0, 2.8, 0.9, "Book DB\n書籍資料", fill="#FFFFFF")
box(0, -3.0, 2.8, 0.9, "Borrow DB\n借閱資料", fill="#FFFFFF")
box(3.8, -3.0, 2.8, 0.9, "User DB\n使用者資料", fill="#FFFFFF")

# =========================
# Actor to UI
# =========================
arrow(-6.2, 3.65, -3.2, 2.8, "查詢 / 借閱 / 查看紀錄")
arrow(6.2, 3.65, 3.2, 2.8, "更新書籍 / 監控紀錄")

# =========================
# UI to Controllers
# =========================
arrow(-3.2, 1.95, -4.8, 0.8, "UC01")
arrow(-3.2, 1.95, -1.6, 0.8, "UC02")
arrow(-3.2, 1.95, 1.6, 0.8, "UC03")

arrow(3.2, 1.95, 4.8, 0.8, "UC04")
arrow(3.2, 1.95, 1.6, 0.8, "UC05")

# =========================
# Controllers to DBs
# =========================
arrow(-4.8, -0.1, -3.8, -2.45, "search/query")
arrow(-1.6, -0.1, 0, -2.45, "create borrow")
arrow(-1.6, -0.1, -3.8, -2.45, "update status")
arrow(1.6, -0.1, 0, -2.45, "query records")
arrow(4.8, -0.1, -3.8, -2.45, "update book")

# =========================
# Auth Service connections
# =========================
arrow(0, -1.15, 3.8, -2.45, "check user", dashed=True)
arrow(-1.6, -0.1, 0, -0.35, "requires login", dashed=True)
arrow(4.8, -0.1, 0, -0.35, "requires admin", dashed=True)

# =========================
# Save
# =========================
out_path = "system_architecture.png"
plt.savefig(out_path, dpi=200, bbox_inches="tight")
plt.close(fig)

print(f"Saved to {out_path}")