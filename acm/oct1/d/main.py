import math

vals = [float(x) for x in raw_input().split()]
leak = vals[0]
obs = vals[-1]

if leak > obs:
	print "%.6f %.6f" % (obs, obs)
else:
	k = vals[1]
	t1 = vals[2]
	t2 = vals[3]
	
	# Quadratic equation for rainfall rate
	b = obs + k * t1 + k * t2
	rate = b + math.sqrt(b**2 - 4 * t1 * leak * k)
	rate /= 2 * t1

	level = rate * t1
	
	if leak < obs:
		print "%.6f %.6f" % (level, level)
	else:
		print "%.6f %.6f" % (obs, level)


