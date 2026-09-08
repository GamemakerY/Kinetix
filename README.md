# Kinetix

Kinetix is desktop device that helps you focus and boosts your productivity with built-in gesture detection.

---

## Visuals & CAD Models

![Full Assembly](images/assembly.png)
*Figure 1: Full 3D assembly render of the Kinetix enclosure.*

| Enclosure Box | Top Lid | PCB Layout |
| :---: | :---: | :---: |
| ![Box View](images/box.png) | ![Lid View](images/lid.png) | ![PCB Render](images/pcb_render.png) |
| *Lower Body Enclosure* | *Lid with OLED Standoffs* | *Custom EasyEDA Board* |

---

## Repository Structure

* `/3d-prints`: 3D printable STL files (`kinetix_box.stl`, `Kinetix_lid.stl`)
* `/cad`: 3D STEP CAD models (`Kinetix_box.step`, `Kinetix_lid.step`)
* `/PCB`: Gerber manufacturing package and 3D PCB STEP file
* `/images`: Visual renders and CAD documentation screenshots
* `/src`: Firmware source code (`main.cpp`)
* `bom.csv`: Bill of Materials

---

Once the project is physically assembled, I plan to train an ML model for gesture detection and make it control the PC using it. It isn't possible or at least genuinely veryt difficult unless I physically have it.
