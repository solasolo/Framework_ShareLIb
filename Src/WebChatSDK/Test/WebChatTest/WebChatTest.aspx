<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebChatTest.aspx.cs" Inherits="Celami.WebChatTest" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
         <asp:Panel ID="Panel1" runat="server">
             ErrorCode:<asp:Label ID="LabelCode" runat="server" Text="Label" ForeColor="Red"></asp:Label>
             &nbsp; Message:<asp:Label ID="LabelMessage" runat="server" Text="Label" ForeColor="Red"></asp:Label>
        </asp:Panel>
     
        <asp:TextBox ID="TextInput" runat="server" Rows="30" TextMode="MultiLine" Width="956px" Height="366px"></asp:TextBox>
        <br />
      
        <asp:Button ID="BtnMenu" runat="server" OnClick="BtnMenu_Click" Text="生成菜单" />
      
    </div>
    </form>
</body>
</html>
