#ifndef PROCESSORWINDOW_H
#define PROCESSORWINDOW_H

#include "PartPageInterface.h"

class ProcessorWindow : public PartPageInterface
{
   public:
      // Constructor
      ProcessorWindow();
      
      // Destructor
      ~ProcessorWindow();
   
   protected:
      // Instantiated virtual function to initialize our vector values
      virtual void initVectorValues();
      
      // Instantiated virtual function to update info for spec windows
      virtual void loadSpecs();
      
      // Instantiated virtual function to load our iamges
      virtual void loadAssets();
};
#endif
