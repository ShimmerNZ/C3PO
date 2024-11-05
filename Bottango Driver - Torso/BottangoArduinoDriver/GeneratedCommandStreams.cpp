#include "GeneratedCommandStreams.h"

namespace GeneratedCommandStreams
{

    //// !!! Insert/edit your animation triggering and playback logic here !!! ////
    /* Some helpful methods:

        BottangoCore::commandStreamProvider.streamIsInProgress()                                        //returns if any animation is currently playing
        BottangoCore::commandStreamProvider.startCommandStream(byte animationID, bool looping)          //starts playing an animation (and stops the current if any)
        BottangoCore::commandStreamProvider.stop()                                                      //stops the current playing animation, if any
    */

    /* Animations key:
        0 - Default Pose
    */

    bool playBegan = false;
    bool playOnStart = false;
    bool loop = false;
    byte startingAnimation = 0;

    // called once per update loop, your logic probably goes here.
    void updatePlayStatus()
    {
        // if haven't started any animations, or if should loop and nothing is playing (IE the last loop ended)
        if (playOnStart && (!playBegan || (loop && !BottangoCore::commandStreamProvider.streamIsInProgress())))
        {
            BottangoCore::commandStreamProvider.startCommandStream(startingAnimation, loop);
            playBegan = true;
        }
    }

    //// ----------------------------------------- /////

    //// GENERATED CODE. You probably don't need to change any of the below ////
    const char SETUP_CHAR_STREAM[] PROGMEM = "rSVPin,25,500,2500,3000,1407\nrSVPin,26,1000,2000,3000,1539\nrSVPin,13,1025,1925,3000,1475\nrSVPin,12,1100,2000,3000,1550\nrSVPin,27,750,2100,3000,1545\nrSVPin,14,800,2200,3000,1376\nrECTrig,myMedia,255\n";
    const char STREAM_DEFAULTPOSE_CHAR_STREAM[] PROGMEM = "sC,14,0,5667,3370,1889,13,3765,-1889,189\nsC,27,0,5667,4822,1889,-13,4427,-1889,-189\nsC,12,0,19750,4096,6583,2,4595,-6583,-192\nsC,13,0,19750,4096,6583,2,4595,-6583,-192\nsCT,myMedia,0\nsC,26,0,1500,4412,375,0,5499,-375,0\nsC,25,0,17083,3714,5694,4,4289,-5695,-6\nsC,26,1500,1100,5499,275,0,4300,-275,0\nsC,26,2600,1100,4300,275,0,4636,-275,0\nsC,26,3700,2000,4636,500,0,6139,-500,0\nsC,26,5700,5867,6139,1467,0,6747,-1467,0\nsC,14,5716,566,3759,194,-135,2794,-193,161\nsC,27,5716,566,4433,194,135,5398,-193,-161\nsC,27,6300,533,5401,182,-126,4455,-180,226\nsC,14,6300,533,2791,182,126,3737,-180,-226\nsC,14,6867,2533,3752,844,2,3803,-844,-4\nsC,27,6867,2533,4440,844,-2,4389,-844,4\nsC,27,9449,233,4398,79,122,4883,-79,-126\nsC,14,9449,233,3794,79,-122,3309,-79,126\nsC,27,9716,233,4884,79,-133,4355,-79,138\nsC,14,9716,233,3308,79,133,3837,-79,-138\nsC,14,9967,667,3849,222,7,3907,-222,-12\nsC,27,9967,667,4343,222,-7,4285,-222,12\nsC,14,10683,766,3906,258,-134,3010,-258,141\nsC,27,10683,766,4286,258,134,5182,-258,-141\nsC,14,11467,83,3007,32,-104,2554,-28,158\nsC,27,11467,83,5185,32,104,5638,-28,-158\nsC,26,11567,1500,6747,375,0,5985,-375,0\nsC,14,11567,1500,2503,503,83,3685,-503,-83\nsC,27,11567,1500,5689,503,-83,4507,-503,83\nsC,27,13067,1033,4507,345,28,4829,-345,-51\nsC,26,13067,3066,5985,767,0,6531,-767,0\nsC,14,13067,1033,3685,345,-28,3363,-345,51\nsC,14,14133,417,3361,140,73,3837,-140,-109\nsC,27,14133,417,4831,140,-73,4355,-140,109\nsC,27,14567,700,4352,235,81,5061,-235,-147\nsC,14,14567,700,3840,235,-81,3131,-235,147\nsC,14,15300,1067,3124,357,68,3889,-357,-120\nsC,27,15300,1067,5068,357,-68,4303,-357,120\nsC,26,16133,2867,6531,756,0,4719,-1096,411\nsC,27,16416,2983,4299,994,-1,4258,-994,21\nsC,14,16416,2983,3893,994,1,3934,-994,-21\nsC,25,17100,300,4288,101,-45,4011,-100,82\nsC,25,17433,300,4000,101,45,4276,-100,-83\nsC,25,17767,200,4288,67,0,4288,-67,0\nsC,25,18000,5850,4289,1950,-9,3865,-1950,13\nsC,26,19000,1633,4719,532,-199,5572,-550,119\nsC,14,19416,233,3930,79,-78,3563,-79,84\nsC,27,19416,233,4262,79,78,4629,-79,-84\nsC,14,19683,216,3566,76,123,4156,-74,-163\nsC,27,19683,216,4626,76,-123,4036,-74,163\nsC,12,19767,800,4596,270,67,5418,-269,-123\nsC,13,19767,800,4596,270,67,5418,-269,-123\nsC,27,19933,633,4008,214,49,4629,-213,-104\nsC,14,19933,633,4184,214,-49,3563,-213,104\nsC,13,20600,767,5422,270,-125,3736,-266,295\nsC,14,20600,4367,3559,1456,13,4035,-1456,-25\nsC,27,20600,4367,4633,1456,-13,4157,-1456,25\nsC,12,20600,767,5422,270,-125,3736,-266,295\nsC,26,20633,3367,5572,1195,-258,5875,-981,413\nsC,13,21416,3566,3720,1191,-147,4521,-1190,-38\nsC,12,21416,3566,3720,1191,-147,4521,-1190,-38\nsC,25,23867,200,3865,68,64,4232,-67,-123\nsC,26,24000,1000,5875,366,-154,3854,-297,0\nsC,25,24100,1867,4261,623,-33,3687,-623,61\nsC,12,25000,1000,4521,334,-41,4096,-334,41\nsC,13,25000,1000,4521,334,-41,4096,-334,41\nsC,26,25000,1000,3854,250,0,4424,-250,0\nsC,27,25000,1000,4157,335,65,4833,-335,-65\nsC,14,25000,1000,4035,335,-65,3359,-335,65\n";
    const char STREAM_DEFAULTPOSE_CHAR_STREAM_LOOP[] PROGMEM = "sC,26,26000,6,4424,3,0,4412,-3,0\nsC,25,26000,3,3717,2,0,3714,-2,0\nsC,14,26000,0,3371,0,0,3371,0,0\n";

    CommandStream setupStream = CommandStream(SETUP_CHAR_STREAM, 0);
    CommandStream stream_DefaultPose = CommandStream(STREAM_DEFAULTPOSE_CHAR_STREAM, 26000, STREAM_DEFAULTPOSE_CHAR_STREAM_LOOP, 593);    

    CommandStream *getCommandStream(byte streamID)
    {
        switch (streamID)
        {
        case 0:
            return &stream_DefaultPose;
        default:
            return NULL;
        }
    }

    CommandStream *getSetupCommandStream()
    {
        return &setupStream;
    }
} // namespace GeneratedCommandStreams
