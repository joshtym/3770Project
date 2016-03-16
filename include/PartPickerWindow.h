#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Forward Declarations
class QTabBar;

class PartPickerWindow : public QMainWindow
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      /// Constructor for the mainWindow
      PartPickerWindow();
   
   private slots:
      void updateWindow(int);
      
   private:
      QTabBar* tabBar;
};

#endif
