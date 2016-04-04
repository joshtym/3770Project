#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QLabel;
class QPushButton;
class QLineEdit;

class InfoWindow : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
      InfoWindow();
      
      // Destructor of class
      ~InfoWindow();
      
      // Function to update the budget
      void updateBudget(double);
   
   signals:
      // Signal sent when budget is updated
      void budgetUpdated(double); 
   
   private slots:
      // Slot to submit the budget
      void budgetSubmission();
      
      // Slot when the text changes
      void textChange(const QString &);
   
   private:
      // Helper function to parse the new budget
      bool parseBudgetAmount(QString);
      
      // Private variables
      std::vector<QHBoxLayout*> layouts;
      std::vector<QLabel*> information;
      QPushButton* updateBudgetButton;
      QLineEdit* budgetIn;
      double budget;
};
#endif
