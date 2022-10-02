import threading
import time
 
def print_data_for(seconds):
		
    # function to print cube of given num
    print("Wait for seconds: ", seconds )
    time.sleep( seconds)
    print("Done after ", seconds, " seconds")
		
 

if __name__ == "__main__":

    # creating thread
    t1 = threading.Thread(target=print_data_for, args=(2,))
    t2 = threading.Thread(target=print_data_for, args=(3,))
 
    t1.start()
    t2.start()
 
    t1.join()
    t2.join()
 
    print("Completed!")
