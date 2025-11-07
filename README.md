Description of Dataset
To Provide a brief overview of the dataset provided, such as the source, number of rows/columns, and a summary of iot_dataset and iot_dataset_mapping included in the dataset.

Reading Data set and Cleaning Dataset 
The Jupyter Notebook was used as the data preprocessing and cleaning phase.
Data Inspection is done by using these functions:
df_main.info()
df_main.head()
df_mapping.head()
And then duplicates,missing values are handled and then datasets are merged 
The cleaned dataset is saved as new file.

After cleaning data the new dataset is saved as iot_cleaned.csv 
Backend :
In backend folder I have created env file and app subfolder. In the app subfolder I have created python files- main.py , load_data.py.
In load_data.py is used to import the cleaned iot_cleaned.csv into the MongoDB database that prepares the database with all sensor records before the API and frontend can access them.
Main.py :
The main.py file serves as the core FastAPI backend for the IoT Data Visualization.
It connects to the MongoDB database and handles all data retrieval requests.
It also includes cors middleware to allow communication with the React frontend and ensures smooth, real-time data exchange between the database and dashboard.

Backend commands that are used in terminal :

Successfully backend is working.
Frontend:
The frontend was developed using React.js to create an interactive IoT dashboard that visualizes real-time sensor data with Apache ECharts.
It communicates with the FastAPI backend using Axios to fetch temperature, humidity, flowrate, pressure, and AQI readings dynamically
And the commands are :
cd frontend/iot-echarts
npm start
Conclusion: 
By integrating FastAPI, MongoDB, and React with ECharts, the system provides a fast, interactive, and scalable dashboard for monitoring IoT devices.
video link: https://drive.google.com/file/d/1O_hFAKsQvhN_ybplgRxFIHlTM9AH5baU/view?usp=sharing 
