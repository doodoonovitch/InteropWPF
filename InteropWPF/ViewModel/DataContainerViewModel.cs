using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataContainerCLR;
using System.ComponentModel;

namespace InteropWPF.ViewModel
{
    public class DataContainerViewModel : INotifyPropertyChanged
    {
        DataWrapper _DataContainer;

        public DataContainerViewModel()
        {
            DataContainer = new DataWrapper();
        }

        public DataWrapper DataContainer
        {
            get { return _DataContainer; }
            set
            {
                _DataContainer = value;
                RaisePropertyChanged("DataContainer");
            }
        }

        #region INotifyPropertyChanged Members

        public event PropertyChangedEventHandler PropertyChanged;

        private void RaisePropertyChanged(string propertyName)
        {
            if(PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }

        #endregion
    }
}
