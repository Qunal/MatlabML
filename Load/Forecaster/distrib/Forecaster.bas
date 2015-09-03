Dim MCLUtil As Object
Dim bModuleInitialized As Boolean
Dim Class1 As Object 

Private Sub InitModule()
    If Not bModuleInitialized Then
        On Error GoTo Handle_Error
        If MCLUtil Is Nothing Then
            Set MCLUtil = CreateObject("MWComUtil.MWUtil7.13")
        End If
        Call MCLUtil.MWInitApplication(Application)
        bModuleInitialized = True
        Exit Sub
Handle_Error:
        bModuleInitialized = False
    End If
End Sub

Function loadForecast(Optional date0 As Variant, Optional hour As Variant, Optional  _
                      temperature As Variant, Optional isWorkingDay As Variant, Optional  _
                      histDate As Variant, Optional histHour As Variant, Optional  _
                      histLoad As Variant) As Variant

    Dim y As Variant

    On Error GoTo Handle_Error

    Call InitModule()

    If Class1 Is Nothing Then
        Set Class1 = CreateObject("Forecaster.Class1.1_0")
    End If

    Call Class1.loadForecast(1, y, date0, hour, temperature, isWorkingDay, histDate,  _
                            histHour, histLoad)
    loadForecast = y

    Exit Function
Handle_Error:
    loadForecast = "Error in " & Err.Source & ": " & Err.Description
End Function
