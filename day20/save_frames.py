import cv2 
import csv 

class ProcessVideo(object): 

	def __init__(self, video_name, count=0):
		self.video_name = video_name 
		self.count = 0

	def read_video(self):
		vidcap = cv2.VideoCapture(self.video_name)
		success,image = vidcap.read()

		self.count = 0
		success = True

		while success:
			success, image = vidcap.read()
			# print("Read a new frame: ", success)
			if(self.count%30==0):	
				cv2.imwrite("frame%d.jpg"%(self.count/30), image)
			self.count+=1
		print("Finished processing the video")

	def read_csv(self, filename):
		self.fields = []
		self.rows = []

		with open(filename, 'r') as csvfile:
			csvreader = csv.reader(csvfile)

			self.fields = next(csvreader)

			for row in csvreader:
				self.rows.append(row)
		print("Total number of rows:{0}".format(len(self.rows[0])))

	def crop_image(self):
		corn_num = 0
		notcorn_num = 0
		for i in range(0, len(self.rows)):
			filename = self.rows[i][0]
			class_label = self.rows[i][3]
			xmin = int(self.rows[i][4])
			ymin = int(self.rows[i][5])
			xmax = int(self.rows[i][6])
			ymax = int(self.rows[i][7])
			img = cv2.imread(self.rows[i][0])
			
			cropped_img = img[ymin:ymax, xmin:xmax]
			cv2.imshow('img', cropped_img)
			
			cv2.waitKey(0)
			cv2.destroyAllWindows()




pv = ProcessVideo("pioneer.avi")
#process video to images
# pv.read_video()
#Crop images and show
# pv.crop_image()
pv.read_csv("corn_labels.csv")
pv.crop_image()