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
    const char SETUP_CHAR_STREAM[] PROGMEM = "rSVPin,12,500,2500,3000,518\nrSVPin,14,500,2500,3000,1522\nrSVPin,27,800,2200,3000,1282\nrSVPin,26,700,2200,3000,1480\nrSVPin,25,1100,1500,3000,1100\nrSVPin,13,500,2100,3000,773\n";
    const char STREAM_DEFAULTPOSE_CHAR_STREAM[] PROGMEM = "sC,25,0,6867,0,1717,0,2869,-1717,0\nsC,26,0,6867,4260,1717,0,7775,-1717,0\nsC,27,0,6100,2822,1489,0,2272,-1832,405\nsC,14,0,3650,4185,1217,18,4752,-1217,-28\nsC,12,0,717,75,239,9,245,-239,-53\nsC,13,0,5700,1395,1425,0,990,-1425,0\nsC,12,717,2933,245,977,218,493,-977,-11\nsC,12,3667,3500,493,1167,-10,199,-1167,18\nsC,14,3667,3500,4753,1167,-10,4459,-1167,18\nsC,13,5700,13500,990,3375,0,405,-3375,0\nsC,27,6100,533,2272,189,-42,550,-166,9\nsC,27,6633,234,550,81,-4,1322,-75,0\nsC,26,6867,333,7775,83,0,8192,-83,0\nsC,27,6867,4700,1322,1175,0,2612,-1175,0\nsC,25,6867,16133,2869,3972,0,4098,-4508,-380\nsC,26,7200,17800,8192,4450,0,5678,-4450,0\nsC,12,7216,1416,199,473,19,578,-472,-74\nsC,14,7216,4583,4459,1528,-36,3614,-1528,44\nsC,12,8632,3167,578,1055,165,646,-1055,-3\nsC,27,11567,5766,2612,1398,0,3554,-1919,93\nsC,12,11833,2717,646,906,6,783,-906,-8\nsC,14,11833,2717,3614,906,22,4087,-906,-27\nsC,12,14567,3433,783,1144,0,656,-1144,102\nsC,14,14567,3433,4087,1144,-5,3944,-1144,-15\nsC,27,17333,967,3554,347,-17,2059,-293,-18\nsC,14,18033,400,3944,134,-16,3792,-133,34\nsC,12,18033,400,652,134,-28,476,-133,45\nsC,27,18300,367,2059,124,8,1174,-121,-264\nsC,14,18483,4483,3791,1495,77,4694,-1493,-690\nsC,12,18483,2033,469,678,-35,305,-678,-17\nsC,27,18667,333,1174,118,258,3441,-104,0\nsC,27,19000,4000,3441,970,0,2902,-1307,415\nsC,13,19200,3800,405,921,0,106,-1250,-613\nsC,12,20516,1217,305,406,10,497,-406,-21\nsC,12,21733,1233,497,411,21,447,-411,-43\nsC,12,23000,1000,452,341,202,1955,-341,-75\nsC,14,23000,1000,4711,341,202,6214,-342,-133\nsC,27,23000,1000,2902,377,-120,188,-280,0\nsC,13,23000,1000,106,378,185,2644,-279,0\nsC,25,23000,1000,4098,354,30,5906,-312,0\nsC,25,24000,1000,5906,250,0,2978,-250,0\nsC,14,24000,1000,6215,351,-114,4260,-347,158\nsC,13,24000,1000,2644,250,0,1370,-250,0\nsC,27,24000,1000,188,250,0,3500,-250,0\nsC,12,24000,1000,1955,351,-114,0,-347,158\n";
    const char STREAM_DEFAULTPOSE_CHAR_STREAM_LOOP[] PROGMEM = "sC,25,25000,646,2978,323,0,0,-323,0\nsC,27,25000,0,2822,0,0,2822,0,0\nsC,26,25000,0,4260,0,0,4260,0,0\nsC,13,25000,0,1395,0,0,1395,0,0\n";

    CommandStream setupStream = CommandStream(SETUP_CHAR_STREAM, 0);
    CommandStream stream_DefaultPose = CommandStream(STREAM_DEFAULTPOSE_CHAR_STREAM, 25000, STREAM_DEFAULTPOSE_CHAR_STREAM_LOOP, 1947);    

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
