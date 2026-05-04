import socket
import time as tm
import csv
UDP_IP = "10.239.224.178"  # 10.239.224.178
UDP_PORT = 1234


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("0.0.0.0", UDP_PORT))

sock.setblocking(False)  # don’t freeze waiting

print("Listening...")

command = input("Command: ")
sock.sendto(command.encode(),(UDP_IP,UDP_PORT))   


while True:

    if command == "True":
       try:
          data, addr = sock.recvfrom(1024)
          electrode_data = data.decode().strip()
          if electrode_data.startswith("A"):
            electrode1 = electrode_data[1:] #grab only the num
            

          elif electrode_data.startswith("B"):
             electrode2 = electrode_data[1:]
             
       
   
          with open("/home/zentinely2k/Documents/PlatformIO/Projects/Arduino_Projects/src/NeuroSync/AI_&_ML_For_Neurosync/NeuroDatabase.csv","a",newline="") as f:
              write = csv.writer(f)
              write.writerow([electrode1,electrode2,1])
         
       except:
           pass
       
    if command == "False":
       try:
          data, addr = sock.recvfrom(1024)
          electrode_data = data.decode().strip()
          if electrode_data.startswith("A"):
            electrode1 = electrode_data[1:] #grab only the num
            

          elif electrode_data.startswith("B"):
             electrode2 = electrode_data[1:]
             
       
   
          with open("/home/zentinely2k/Documents/PlatformIO/Projects/Arduino_Projects/src/NeuroSync/AI_&_ML_For_Neurosync/NeuroDatabase.csv","a",newline="") as f:
              write = csv.writer(f)
              write.writerow([electrode1,electrode2,0])
         
       except:
           pass
#The goal is to think/perform an action when input is True and set the value to 1, that way,the mdoel can be traine to map all of the captures values as a gesture, then, when doing anything but the gesture
#we will select False as the input to record the non-related values as zero