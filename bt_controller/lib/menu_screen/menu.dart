import 'package:flutter/material.dart';
import 'package:flutter_neumorphic/flutter_neumorphic.dart';
import '../homepage.dart';
import 'package:flutter/services.dart';



class MenuScreen extends StatelessWidget {
  // void initState() {
  //   initState();
  //   SystemChrome.setPreferredOrientations([
  //     DeviceOrientation.portraitUp,
  //     DeviceOrientation.portraitDown,
  //   ]);
  // }
  //  @override
  // dispose() {
  //   SystemChrome.setPreferredOrientations([
  //     DeviceOrientation.portraitUp,
  //     DeviceOrientation.portraitDown,
  //   ]);
  //   dispose();
  // }
  @override 
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color.fromARGB(115, 60, 60, 60),
      body: Center(
        child: Container(
          color:Color.fromARGB(255, 64, 64, 64),
          width: 300,
          //child: IntrinsicWidth(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                // Text('R.U.P.E.R.T',
                //   style: TextStyle(color: Color.fromARGB(255, 255, 255, 255),),
                //   textAlign: TextAlign.center,),
                NeumorphicText(
                    "R.U.P.E.R.T",
                    style: NeumorphicStyle(
                      depth: 4,  //customize depth here
                      color: Colors.white, //customize color here
                      intensity: .4,
                    ),
                    textStyle: NeumorphicTextStyle(
                      fontSize: 18, 
                    ),
                ),
                Container(
                  padding:EdgeInsets.all(15),
                  child: Divider(
                    thickness: 2,
                    color: Color.fromARGB(255, 255, 255, 255),
                  ),
                ),
                // Manual Button
                Container(
                  child: Align(
                    child: SizedBox(
                      width: 200,

                        child: NeumorphicButton(
                            onPressed: () {
                              Navigator.of(context).push(
                                MaterialPageRoute(builder: (context) { 
                                  return HomePage(); 
                                }),
                              );
                            },
                          style: NeumorphicStyle(
                            shape: NeumorphicShape.flat,
                            intensity: .4,
                            depth: 9,
                            color: Color.fromARGB(255, 61, 61, 61),
                            //lightSource:LightSource.topRight
                        ),
                          
                        child:Align(
                          alignment: Alignment.center,
                          child: Text('Manual',),),
                      ),
                          
                        ),
                    ),
                ),
                Container(
                  child:SizedBox( 
                    width: 200,
                    height: 30)
                ),
                Container(
                  child: Align(
                    child: SizedBox(
                      width: 200,
                      child: NeumorphicButton(
                        // Navigate to view page (currently named "homepage.dart")
                        onPressed: () {
                        Navigator.of(context).push(
                        MaterialPageRoute(builder: (context) { 
                          return HomePage(); })
                        );
                        },
                        style: NeumorphicStyle(
                          shape: NeumorphicShape.flat,
                          intensity: .4,
                          depth: 9,
                          color: Color.fromARGB(255, 61, 61, 61),
                          //lightSource:LightSource.topRight
                        ),
                          
                        child:Align(
                          alignment: Alignment.center,
                          child: Text('Automatic',),),
                      ),
                    ),
                  ),
                ),
          ],)
        ),
      //),
      ),
    );
  }
}