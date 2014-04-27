from PyQt4.QtGui import *
from PyQt4.QtCore import *
import sys

app = QApplication(sys.argv);
qlb = QLabel("Hello PyQT!");

font = QFont("Courier New", 36);
font_dlg = QFontDialog();
font_dlg.setCurrentFont(font)
temp_font, ok = font_dlg.getFont();

if ok:
    font = temp_font;

qlb.setFont(font);

color = QColorDialog.getColor();

if color.isValid():
    p = qlb.palette();
    p.setColor(QPalette.WindowText, color);
    qlb.setPalette(p);

qlb.setAlignment(Qt.AlignCenter);
qlb.setWindowTitle("Hello");
qlb.setWindowIconText("GNU");
qlb.setWindowIcon(QIcon("535px-Heckert_GNU_white.svg.png"));

screen = QDesktopWidget().screenGeometry();
size = qlb.sizeHint();

x = (screen.width() - size.width()) / 2;
y = (screen.height() - size.height()) / 2;

qlb.move(x, y);
qlb.show();

sys.exit(app.exec_())
