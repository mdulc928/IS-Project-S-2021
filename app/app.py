import sys
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QIcon

class App(QWidget):
    def __init__(self):
        super().__init__()
        self.title = "PyQt5 simple window from pythonspot.com"
        self.left = 10
        self.top = 10
        self.width = 640
        self.height = 480
        self.initUI()
    
    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)
        self.addItems()
        self.show()

    def addItems(self):
        self.label = QtWidgets.QLabel(self)
        self.label.setText("Path")
        self.label.move(30, 50)

        self.b1 = QtWidgets.QPushButton(self)
        self.b1.setText("My button")
        self.b1.clicked.connect(self.clicked)
    
    def clicked(self):
        self.label.setText("The button there")
        self.update()

    def update(self):
        self.label.adjustSize()
    

if __name__ == "__main__":
    app = QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())