from os import system, path

import time
from threading import Thread

def main():
	cmd = 'rm -R features; rm -R target; mkdir features; mkdir target; ./make.sh'
	system(cmd)

	video = 'BasketballPass'
	qps = ['22', '27', '32', '37']

	MAX_THREADS = 4  # numero maximo de threads que executarao
	INI_THREADS = 0
	threads = []     # lista de threads
	for i in range (MAX_THREADS):
		qp = qps.pop(0)
		print ('Starting ' + video + ' Core ' + str(i + INI_THREADS))
		threads.append(Th(i + INI_THREADS, video, qp))
		threads[i].start()

	while(True):
		dead_threads = 0
		for i, thread in enumerate(threads):
			qp = None
			if not thread.isAlive():
				try:
					qp = qps.pop(0)
				except:
					dead_threads += 1
				if qp != None:
					print('Starting ' + qp)
					threads[i] = Th(i + INI_THREADS, video, qp)
					threads[i].start()

		if dead_threads == MAX_THREADS:
			return
		time.sleep(60)



class Th(Thread):
	def __init__ (self, core, video, qp):
		Thread.__init__(self)
		self.core   = str(core)
		self.video  = video
		self.qp     = qp

	def run(self):

		video_path = {
			'BasketballPass': 					  ['/home/lindino/Documentos/rawVideos/BasketballPass_416x240_50.yuv', 8],
		}

		in_file = video_path[self.video][0]
		in_frames = str(video_path[self.video][1])
		encoderCfgFile = "encoder_randomaccess_vtm.cfg"


		outFile = "out_VTM/" + self.video + "_" + self.qp + "_features.txt"
		bsFile = "video_bin/" + self.video + "_" + self.qp + "_features.bin"

		cmd = "taskset -c " + self.core + " ./bin/EncoderAppStaticd -c cfg/" + encoderCfgFile + " -c cfg/per-sequence/" + self.video + ".cfg --FramesToBeEncoded=" + in_frames + " --QP=" + self.qp + " --SIMD=SCALAR --InputFile=" + in_file + " --VideoName=" + self.video + " --BitstreamFile=" + bsFile + " > " + outFile
		#print (cmd)
		system(cmd)


if __name__ == '__main__':
    main()
