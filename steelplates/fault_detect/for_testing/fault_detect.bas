Dim MCLUtil As Object
Dim bModuleInitialized As Boolean
Dim Class1 As Object 

Private Sub InitModule()
    If Not bModuleInitialized Then
        On Error GoTo Handle_Error
        If MCLUtil Is Nothing Then
            Set MCLUtil = CreateObject("MWComUtil.MWUtil8.3")
        End If
        Call MCLUtil.MWInitApplication(Application)
        
        bModuleInitialized = True
        Exit Sub
Handle_Error:
        bModuleInitialized = False
    End If
End Sub

Function steelfault(Optional in0 As Variant) As Variant

    Dim out As Variant

    On Error GoTo Handle_Error

#If CBool(Win64) Then
    steelfault = "This Excel Add-In is built for 32 bit Excel and you are using 64 bit Excel. Rebuild the Excel Add-In with 64 bit MATLAB."
    Exit Function
#End If

    Call InitModule()

    If Class1 Is Nothing Then
        Set Class1 = CreateObject("fault_detect.Class1.1_0")
    End If

    Call Class1.steelfault(1, out, in0)
    steelfault = out

    Exit Function
Handle_Error:
    steelfault = "Error in " & Err.Source & ": " & Err.Description
End Function
