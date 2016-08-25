import sys
from PyQt4 import QtGui


if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    main_window = MainWindowClass()
    main_window.show()
    sys.exit(app.exec_())
    

window=QtGui.QWidget()
window.setGeometry(0,0,500,300)
window.setWindowTitle("Pros")
window.show()
