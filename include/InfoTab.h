#ifndef INFOTAB_H
#define INFOTAB_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QLabel;
class QPushButton;
class QPixMap;

class InfoTab : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
   InfoTab();
      
      // Destructor of class
      ~InfoTab();
   
   /* signals: */
      void budgetupdated(double budg);      
   /* private slots: */

   
   public slots:
      void resizeEvent(QResizeEvent*);
   
   private:
      // void loadAssets();
      
      std::vector<QHBoxLayout*> layouts;
      std::vector<QLabel*> information;
};
#endif
