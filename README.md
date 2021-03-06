<!---![](Documentation/Img/SemLog.jpg)-->

![](Documentation/Img/PaP_SemLog.jpg)

# USemLog

Semantic logging plugin for Unreal Engine. Logs symbolic and sub-symbolic data to a KnowRob compatible format.

## Capabilities

![](Documentation/GIF/ameva2_semantic_map.gif)

![](Documentation/GIF/ameva2_ep_replay.gif)

![](Documentation/GIF/ameva2_queries.gif)

![](Documentation/GIF/ameva2_cv.gif)

# Related publications

```bibtex
@misc{haidu2020automated,
    author={Andrei Haidu and Michael Beetz},
    title={Automated acquisition of structured, semantic models of manipulation activities from human VR demonstration}, 
    year={2020},
    eprint={2011.13689},
    archivePrefix={arXiv},
    primaryClass={cs.AI}
}

@inproceedings{haiduameva19,
    author={Andrei Haidu, Michael Beetz},
    title={Automated Models of Human Everyday Activity based on Game and Virtual Reality Technology}, 
    booktitle={2019 International Conference on Robotics and Automation (ICRA)}, 
    year={2019},
    pages={2606-2612},
    doi={10.1109/ICRA.2019.8793859}}

@inproceedings{haidukrsim18,
    author={Andrei Haidu, Daniel Bessler, Asil Kaan Bozcuoglu, Michael Beetz},
    title={KnowRob_SIM - Game Engine-Enabled Knowledge Processing Towards Cognition-Enabled Robot Control},
    booktitle={2018 IEEE/RSJ International Conference on Intelligent Robots and Systems (IROS)}, 
    year={2018},
    pages={4491-4498},
    doi={10.1109/IROS.2018.8593935}}
}
```

# Usage:

#### Include the plugin to your project
* Add the plugin to your project (e.g `MyProject/Plugins/USemLog`)

#### Semantically annotate skeletal components:

* [SkelAnnotationTutorial](Documentation/SkelAnnotationTutorial.md)

#### Proto msgs compilation

* [ProtoMsgs](Documentation/ProtoMsgs.md)

#### CV scan video generation

* [CV_ffmpg](Documentation/CV_ffmpg.md)

#### Semantic logger manager usage

* [SLM](Documentation/SLM.md)

