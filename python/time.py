import datetime

current_time = datetime.datetime.now()  

# Printing attributes of now().  
print ("```" + str(current_time.year) + ':' + str(current_time.month) + ':' + str(current_time.day) + ':' + str(current_time.hour) + ':' + str(current_time.minute) + ':' + str(current_time.second) + ':' + str(current_time.microsecond) + "```")