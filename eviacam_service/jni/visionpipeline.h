/////////////////////////////////////////////////////////////////////////////
// Name:        visionpipeline.h
// Purpose:  
// Author:      Cesar Mauri Loba (cesar at crea-si dot com)
// Modified by: 
// Created:     
// Copyright:   (C) 2008-15 Cesar Mauri Loba - CREA Software Systems
// 
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

#ifndef VISIONPIPELINE_H
#define VISIONPIPELINE_H

#include "crvimage.h"
#include "normroi2.h"
#include "facedetection.h"

namespace  eviacam {

class VisionPipeline
{
public:
	// Methods
	VisionPipeline (const char* cascadePath);
	virtual ~VisionPipeline();

	bool processImage (CIplImage& image, float& xVel, float& yVel);

	bool GetTrackFace () const { return m_trackFace; }
	void SetTrackFace (bool state) { m_trackFace= state; }

	int GetCpuUsage ();
	void SetCpuUsage (int value);

private:
	// Face detector
	FaceDetection m_faceDetection;

	// Track area
	bool m_trackFace;
	CIplImage m_imgPrev, m_imgCurr;
	NormROI2 m_floatTrackArea;

	// Corner array
	enum { NUM_CORNERS = 15 };
	CvPoint2D32f m_corners[NUM_CORNERS];
	int m_corner_count;
	
	//
	// Private methods
	//
	void allocWorkingSpace (CIplImage &image);
	void newTracker(CIplImage &image, float &xVel, float &yVel);
};

}

#endif